#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;

	(void)envp;

	init_env(envp);
	char	*line;
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


void	init_env(char **envp)
{
	int		i;
	t_env	*list;

	list = malloc(sizeof(t_env));
	i = 0;
	while (envp[i])
	{
		list = add_envp_to_env(list, &envp[i], i);
		i++;
	}
}

// t_env     *add_list(t_env *list, char *data)
// {
// 	t_env    *cur;
//     t_env    *cell;

//     cur = list;

//     cell = create_cell(data);
//     if (isempty(list))
//     	return (cell);
//     while (cur->next != NULL)
//         cur = cur->next;
//     cur->next = cell;
//     return (list);
// 	free(cell);
// 	return (0);
// }

// void	print_env(t_env *env)
// {
// 	while (env)
// 	{
// 		ft_printf("%s\n", env->content);
// 		env = env->next;
// 	}
// }

// t_env	*create_cell(char *data)
// {
// 	t_env	*cell;

// 	cell = malloc(sizeof(cell));
// 	if(!cell)
// 		return (NULL);
// 	cell->content = data;
// 	cell->next = NULL;
// 	return(cell);
// }

// t_env   *empty_list(void)
// {
// 	return (NULL);
// }

// int    isempty(t_env *L)
// {
//     return (L == NULL);
// }