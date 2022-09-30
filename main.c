#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	char	*line;
	init_env(envp);
	while (1)
	{
		line = readline("\033[0;35mqbonvin_minishell ▸ \033[0;37m");
		if (parsing_line(line) == 0)
			split_with_pipe(line);
		add_history(line);
	}
	return (EXIT_SUCCESS);
}

void printf_env(t_env *list)
{
	int	i;

	i = 0;
    while (list)
    {
        //printf("index = [%d]", i);
        printf("%s\n", list->content);
		list = list->next;
		i++;
    }
}

t_env	*create_cell(char **envp)
{
	(void)envp;
	t_env	*cell;
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
	t_env 	*prec;
	t_env 	*curr;
	t_env 	*cell;
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
