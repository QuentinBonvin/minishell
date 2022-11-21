/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:30:36 by qbonvin           #+#    #+#             */
/*   Updated: 2022/11/21 12:35:53 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin(t_shell *list, char **envp, char *line)
{
	t_cmd	*current;
	int		i;

	i = 0;
	(void)envp;
	(void)line;
	current = list->head;
	if (current->tab[0] == NULL)
		return (-1);
	if (ft_strncmp(current->tab[0], "pwd", 4) == 0)
		return (0);
	else if ((ft_strncmp(current->tab[0], "cd", 3) == 0))
		return (0);
	else if ((ft_strncmp(current->tab[0], "echo", 5)) == 0)
		return (0);
	else if ((ft_strncmp(current->tab[0], "export", 7) == 0))
		return (0);
	else if (ft_strncmp(current->tab[0], "unset", 6) == 0)
		return (0);
	else if (ft_strncmp(current->tab[0], "env", 4) == 0)
		return (0);
	else if (ft_strncmp(current->tab[0], "exit", 5) == 0)
		return (0);
	return (-1);
}

int	exec_builtin(t_cmd *current, t_shell *list, char *line, t_env *env)
{
	int	i;
	int	l;

	i = 0;
	if (current->tab[0] == NULL)
		return (-1);
	l = ft_strlen(current->tab[0]) + 1;
	if (ft_strncmp(current->tab[0], "pwd", l) == 0)
		return (call_pwd());
	else if (ft_strncmp(current->tab[0], "cd", l) == 0)
		return (call_cd(current, env));
	else if (ft_strncmp(current->tab[0], "echo", l) == 0)
		return (mini_echo(current, current->tab, list));
	else if (ft_strncmp(current->tab[0], "export", l) == 0)
		return (sort_list(env, current->tab));
	else if (ft_strncmp(current->tab[0], "unset", l) == 0)
		return (call_unset(env, current->tab));
	else if (ft_strncmp(current->tab[0], "env", l) == 0)
		return (printf_env(env, current));
	else if (ft_strncmp(current->tab[0], "exit", l) == 0)
		return (mini_exit(current, current->tab[1], line, env));
	return (-1);
}

char	*search_env(t_env *env)
{
	int		i;
	t_env	*curr;

	i = 0;
	curr = env->env_head;
	while (curr)
	{
		if (ft_strcmp_env(curr->content, "PATH=") == 0)
		{
			return (curr->content);
		}
		curr = curr->prev;
	}
	return (NULL);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' && s2[i] != '\0') && s1[i] == s2[i])
		i++;
	if (*s1 == *s2)
		return (0);
	else
		return (-1);
}
