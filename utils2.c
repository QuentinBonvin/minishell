/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:26:38 by qbonvin           #+#    #+#             */
/*   Updated: 2022/11/21 12:18:31 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_all(t_shell *list, t_env *env, char *line)
{
	free(line);
	free_env(env);
	free(list);
	free(env);
}

t_env	*create_node(char *node)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (new)
	{
		new->content = ft_strdup(node);
		new->prev = NULL;
	}
	return (new);
}

char	**convert_list(t_env *env)
{
	char	**env_array;
	int		length;
	t_env	*curr;
	int		i;

	i = 0;
	length = ft_count_env(env);
	curr = env->env_head;
	env_array = (char **)malloc(sizeof(char **) * (length + 2));
	while (curr)
	{
		env_array[i] = curr->content;
		curr = curr->prev;
		i++;
	}
	return (env_array);
}

int	check_command_not_found(int i, char **envp, t_cmd *curr)
{
	(void)i;
	execve(curr->tab[0], curr->tab, envp);
	if (curr->tab[0] != NULL)
	{
		printf("minishell: %s: command not found \n", curr->tab[0]);
		g_exit_status = 127;
		return (1);
	}
	return (0);
}

int	count_space(char *line)
{
	int	i;
	int	space;

	i = 0;
	space = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			space++;
		i++;
	}
	return (space);
}
