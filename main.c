/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:24:19 by qbonvin           #+#    #+#             */
/*   Updated: 2022/09/26 15:39:52 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void printf_env(t_list_env *list)
{
    t_node_env *actuel;

	actuel = list->first_node;
    if (list == NULL)
        exit(EXIT_FAILURE);
    while (actuel != NULL)
    {
        printf("%s\n", actuel->content);
		actuel = actuel->next;
    }
}

t_list_env	*create_env(char **envp)
{
	(void)envp;
	t_list_env	*list;
	t_node_env	*node;

	list = malloc(sizeof(t_list_env));
	node = malloc(sizeof(t_node_env));
	if (list == NULL || node == NULL)
		exit (EXIT_FAILURE);
	node->content = NULL;
	node->next = NULL;
	list->first_node = node;
	return (list);
}

void		add_envp_to_env(t_list_env *env, char **envp, int i)
{
	t_node_env *new_node;

	new_node = malloc(sizeof(t_node_env));
	if (env == NULL || new_node == NULL)
		exit (EXIT_FAILURE);
	new_node->content = envp[i];
	new_node->next = env->first_node;
	env->first_node = new_node;
}


// int	init_env(t_env **new_env, char **envp)
// {
// 	int	i;

// 	i = 0;
// 	while (envp[i])
// 	{
// 		*new_env = add_list(*new_env, envp[i]);
// 		i++;
// 	}
// 	return (0);
// }

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