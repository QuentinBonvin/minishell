/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:31:53 by qbonvin           #+#    #+#             */
/*   Updated: 2022/11/18 15:53:57 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sort_and_swap(char **env_array, int l)
{
	int		swapped;
	char	*tmp;
	int		i;

	swapped = 0;
	while (env_array && swapped == 0)
	{
		swapped = 1;
		i = -1;
		while (++i < (l - 1))
		{
			if (ft_compare(env_array[i], env_array[i + 1]) > 0)
			{
				tmp = env_array[i];
				env_array[i] = env_array[i + 1];
				env_array[i + 1] = tmp;
				swapped = 0;
			}
		}
		l--;
	}
}

int	check_arg(char *arg)
{
	int	i;

	i = 0;
	if (ft_isdigit(arg[i]) == 1)
		return (-1);
	while (arg[i] && arg[i] != '=')
	{
		if (ft_isalpha(arg[i]) == 0)
			return (2);
		i++;
	}
	if (arg[i] != '=')
		return (3);
	return (1);
}

void	replace_in_env(t_env *env, char *envp, char *arg)
{
	t_env	*curr;

	curr = env->env_head;
	while (curr)
	{
		if (curr->content == envp)
		{
			free(curr->content);
			curr->content = ft_strdup(arg);
		}
		curr = curr->prev;
	}
}

char	*check_if_in_env(t_env *env, char *arg)
{
	t_env	*curr;
	int		i;
	int		l;

	curr = env->env_head;
	l = ft_strlen(arg);
	i = 0;
	while (curr)
	{
		if (ft_strncmp(curr->content, arg, l) == 0)
			return (curr->content);
		curr = curr->prev;
	}
	return (NULL);
}
