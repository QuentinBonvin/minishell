/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:31:42 by qbonvin           #+#    #+#             */
/*   Updated: 2022/11/18 15:47:58 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	sort_list(t_env *env, char **arg)
{
	int		i;
	int		ret;

	i = 1;
	ret = 0;
	if (arg[i] == NULL)
		print_array(env);
	else
	{
		while (arg[i])
		{
			combine(arg[i], env);
			i++;
		}
	}
	return (0);
}

void	combine(char *arg, t_env *env)
{
	int	j;
	int	ret;

	j = -1;
	while (arg[++j])
	{
		ret = is_equal(arg, j);
		if (ret != -1)
			break ;
	}
	if (ret != -1)
		replace_value(arg, ret, env);
	else
		add_new(env, arg);
}

int	is_equal(char *arg, int j)
{
	int	ret;

	ret = 0;
	if (arg[j] == '=')
	{
		ret = 1;
		return (j);
	}
	return (-1);
}

void	add_new(t_env *env, char *arg)
{
	char	*envp;

	envp = NULL;
	envp = check_if_in_env(env, arg);
	if (envp == NULL)
		add_export_to_env(&env->env_tail, arg);
}

void	replace_value(char *arg, int j, t_env *env)
{
	char	*tmp;
	char	*envp;

	tmp = ft_substr(arg, 0, j);
	envp = check_if_in_env(env, tmp);
	if (envp != NULL)
		replace_in_env(env, envp, arg);
	else
		add_export_to_env(&env->env_tail, arg);
	free(tmp);
}
