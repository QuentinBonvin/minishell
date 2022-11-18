/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bins.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:47:15 by qbonvin           #+#    #+#             */
/*   Updated: 2022/11/18 17:40:10 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**bins(t_cmd *cmd, t_env *env)
{
	char	**split_path;
	char	*path;
	char	*pathtmp;
	int		i;

	(void)cmd;
	i = -1;
	if (search_env(env) == NULL)
	{
		g_exit_status = 127;
		return (NULL);
	}
	else
	{
		path = search_env(env);
		split_path = ft_split(path, ':');
		pathtmp = split_path[0];
		split_path[0] = ft_substr(split_path[0], 5, ft_strlen(split_path[0]));
		free(pathtmp);
	}
	return (split_path);
}

void	bins_execute(char **split_path, char **envp, t_cmd *cmd)
{
	int		i;
	int		y;
	char	*tmp;
	char	*tmp2;

	i = 0;
	y = -1;
	tmp2 = NULL;
	no_home(split_path, cmd, i);
	while (split_path[++y])
	{
		tmp = ft_strjoin(split_path[y], "/");
		if (cmd->tab[0] != NULL)
			tmp2 = ft_strjoin(tmp, cmd->tab[0]);
		free (tmp);
		if (!access(tmp2, X_OK))
		{
			if (execve(tmp2, cmd->tab, envp) == -1)
				i++;
		}
		free(tmp2);
	}
	check_command_not_found(i, tmp2, cmd);
}

void	free_split_path(char **split_path)
{
	int	i;

	i = 0;
	while (split_path[i])
	{
		free(split_path[i]);
		i++;
	}
	free(split_path);
}

void	free_tab_cmd(t_shell *list)
{
	int	i;

	i = 0;
	while (list->cmd->tab[i])
	{
		free(list->cmd->tab[i]);
		i++;
	}
	free(list->cmd->tab);
}

void	no_home(char **split_path, t_cmd *curr, int i)
{
	if (split_path == NULL)
	{
		check_command_not_found(i, NULL, curr);
		return ;
	}
	return ;
}
