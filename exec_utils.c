/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:43:47 by qbonvin           #+#    #+#             */
/*   Updated: 2022/11/18 14:44:14 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_env(char *name, char *pwd, t_env *env)
{
	char	*var_ok;
	char	*tmp;
	char	*new;

	tmp = ft_strjoin(name, "=");
	var_ok = check_if_in_env(env, tmp);
	if (var_ok != NULL)
	{
		new = ft_strjoin(tmp, pwd);
		replace_in_env(env, var_ok, new);
	}
	return (0);
}

int	home_not_set(char *home)
{
	if (home == NULL)
	{
		printf("Home not set\n");
		return (0);
	}
	return (-1);
}
