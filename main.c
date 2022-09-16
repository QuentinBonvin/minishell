/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:24:19 by qbonvin           #+#    #+#             */
/*   Updated: 2022/09/16 14:56:58 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)envp;
	(void)argv;
	t_env	*new_env;
	char	*line;
	
	new_env = NULL;
	while (1)
	{
		//init_env(&new_env, envp);
		
		line = readline("\033[0;35mqbonvin_minishell ▸ \033[0;37m");
		add_history(line);
		//split_argument(argc, argv);
		print_env(new_env);
	}
	return (EXIT_SUCCESS);
}

int	init_env(t_env **new_env, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		*new_env = add_list(*new_env, envp[i]);
		i++;
	}
	return (0);
}

t_env     *add_list(t_env *list, char *data)
{
	t_env    *cur;
    t_env    *cell;

    cur = list;

    cell = create_cell(data);
    if (isempty(list))
    	return (cell);
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = cell;
    return (list);
	free(cell);
	return (0);
}

void	print_env(t_env *env)
{
	while (env)
	{
		ft_printf("%s\n", env->content);
		env = env->next;
	}
}

t_env	*create_cell(char *data)
{
	t_env	*cell;

	cell = malloc(sizeof(cell));
	if(!cell)
		return (NULL);
	cell->content = data;
	cell->next = NULL;
	return(cell);
}

t_env   *empty_list(void)
{
	return (NULL);
}

int    isempty(t_env *L)
{
    return (L == NULL);
}