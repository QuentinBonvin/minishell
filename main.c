#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*line;

	(void)argc;
	(void)argv;
	(void)envp;
	//init_env(envp);
	while (1)
	{
		line = readline("\033[0;35mqbonvin_minishell ▸ \033[0;37m");
		if (!check_error(line))
		{
			printf("error after check error\n");
			return (0);
		}	
		signal(SIGINT, sig_handler);
		// signal(SIGQUIT, SIG_IGN);
		if (parsing_line(line) == 0)
			split_with_quote(line);
		add_history(line);
	}
	return (EXIT_SUCCESS);
}

void	sig_handler(int signum)
{
	if (signum == SIGINT)
	{
		rl_on_new_line();
		rl_replace_line("", 1);
		// rl_redisplay();
	}
}

void	printf_env(t_env *list)
{
	int	i;

	i = 0;
	while (list)
	{
		printf("%s\n", list->content);
		list = list->next;
		i++;
	}
}

t_env	*create_cell(char **envp)
{
	t_env	*cell;

	(void)envp;
	cell = malloc(sizeof(t_env));
	if (!(cell))
		return (NULL);
	cell->content = NULL;
	cell->next = NULL;
	cell->prev = NULL;
	return (cell);
}

t_env	*add_envp_to_env(t_env *list, char **envp, int position)
{
	t_env	*prec;
	t_env	*curr;
	t_env	*cell;
	int		i;

	curr = list;
	i = 0;
	cell = create_cell(envp);
	if (list == NULL)
	{	
		printf("Test\n");
		return (cell);
	}
	while (i < position)
	{
		curr->content = envp[i];
		prec = curr;
		curr = curr->next;
		i++;
	}
	prec->next = cell;
	cell->next = curr;
	return (list);
}
