/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:27:00 by qbonvin           #+#    #+#             */
/*   Updated: 2022/11/18 19:29:43 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	call_unset(t_env *env, char **var)
{
	int	i;

	i = 1;
	if (var[i] == NULL)
		return (0);
	while (var[i])
	{
		if (check_if_in_env(env, var[i]) == NULL)
			return (0);
		ft_remove_from_list(env, var[i]);
		i++;
	}
	return (0);
}

void	ft_remove_from_list(t_env *env, char *var)
{
	t_env	*curr;
	t_env	*tmp;
	int		l;

	curr = env->env_head;
	l = (ft_strlen(var) + 1);
	if (ft_delete_first_node(&env->env_head, curr, var))
		return ;
	while (curr != NULL && ft_strncmp2(curr->content, var, l) != 0)
	{
		tmp = curr;
		curr = curr->prev;
	}
	if (ft_strncmp2(curr->content, var, l) == 0)
	{
		tmp->prev = curr->prev;
		free(curr->content);
		curr->content = NULL;
		free(curr);
		curr = NULL;
	}
	else
		return ;
}

int	ft_delete_first_node(t_env **env_head, t_env *curr, char *var)
{
	if (!(ft_strcmp(curr->content, var)))
	{
		*env_head = curr->prev;
		free(curr);
		return (1);
	}
	return (0);
}
