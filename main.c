#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;
	char	*line;
	//init_env(envp);
	while (1)
	{
		line = readline("\033[0;35mqbonvin_minishell ▸ \033[0;37m");
		parsing_line(line);
		add_history(line);
	}
	return (EXIT_SUCCESS);
}

void printf_env(t_env *list)
{
	int	i;

	i = 0;
    if (list == NULL)
        exit(EXIT_FAILURE);
    while (list)
    {
        printf("index = [%d]", i);
        printf("%s\n", list->content);
		list = list->next;
		i++;
    }
}

t_env	*create_cell(char **envp)
{
	t_env	*cell;
	cell = malloc(sizeof(t_env));
	if (!(cell))
		return (NULL);
	cell->content = *envp;
	cell->next = NULL;
	cell->prev = NULL;
	return (cell);
}

t_env	*add_envp_to_env(t_env *list, char **envp, int position)
{
	t_env *prec;
	t_env *curr;
	t_env *cell;
	int		i;

	curr = list;
	i = 0;
	cell = create_cell(envp);
	if (list == NULL)
		return (cell);
	while (i < position)
	{
		i++;
		prec = curr;
		curr = curr->next;
	}
	printf("Test\n");
	prec->next = cell;
	cell->next = curr;
	return (list);
}
