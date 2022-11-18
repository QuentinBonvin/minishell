/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:43:30 by qbonvin           #+#    #+#             */
/*   Updated: 2022/11/18 14:44:18 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	call_cd(t_cmd *curr, t_env *env)
{
	char	*home;
	int		res;
	char	*pwd;
	int		i;

	i = 0;
	res = 0;
	pwd = get_env("PWD", env);
	home = get_env("HOME", env);
	if (home_not_set(home) == 0)
		return (0);
	if (curr->tab[1])
	{
		res = get_direction(curr->tab[1], home, curr);
		set_env("OLDPWD", pwd, env);
		set_env("PWD", home, env);
	}
	else if (!curr->tab[1])
	{
		res = chdir(home);
		set_env("PWD", home, env);
		set_env("OLDPWD", pwd, env);
	}
	pwd = getcwd(NULL, 0);
	return (res);
}

int	get_direction(char *arg, char *home, t_cmd *curr)
{
	int	res;
	int	i;

	i = 0;
	if (arg[i] == '~')
	{
		res = chdir(home);
		return (res);
	}
	res = chdir(arg);
	{
		if (res != 0)
			ft_error(curr->tab);
	}
	home = getcwd(NULL, 0);
	return (res);
}

char	*get_env(char *name, t_env *env)
{
	t_env	*curr;
	char	*home;
	int		l;
	int		i;

	i = 0;
	curr = env->env_head;
	l = ft_strlen(name) + 1;
	home = NULL;
	while (curr != NULL)
	{
		if ((name[i] == '=' || name[i] == '\0') && (curr->content[i] == '='))
			break ;
		if (curr->content[i] == name[i])
			i++;
		else
		{
			curr = curr->prev;
			i = 0;
		}
	}
	if (curr == NULL)
		return (0);
	home = join_home(curr->content, l);
	return (home);
}

char	*join_home(char *curr, int length)
{
	char	*home;
	size_t	end;

	end = ft_strlen(curr);
	home = ft_substr(curr, length, end);
	return (home);
}
