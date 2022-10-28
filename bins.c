#include "minishell.h"

void	bins(t_shell *list, char **envp)
{
	char	**split_path;
	char	*path;
	int		i;

	i = -1;
	path = search_env(list);
	split_path = ft_split(path, ':');
	split_path[0] = ft_substr(split_path[0], 5, ft_strlen(split_path[0]));
	while (split_path[++i])
		split_path[i] = ft_strjoin(split_path[i], "/");
	i = -1;
	while (split_path[++i])
		split_path[i] = ft_strjoin(split_path[i], list->tail->tab[0]);
	bins_execute(split_path, list, envp);
}

void	bins_execute(char **split_path, t_shell *list, char **envp)
{
	int i;

	i = 0;
	pid_t	child_pid;

	child_pid = fork();
	if (child_pid == 0)
	{
		while (split_path[i])
		{
			if (execve(split_path[i], &list->tail->tab[0], envp) == -1)
				i++;
		}
		// if (i == 9)
		// 	ft_printf(list->tail->tab[0], "%s");
		// 	ft_printf(": command not found\n");
	}
	else
	{
		wait(&child_pid);
	}
	free_split_path(split_path);
	//free_tab_cmd(list);
}

void	free_split_path(char **split_path)
{
	int i;

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
	int i;

	i = 0;
	while (list->cmd->tab[i])
	{
		free(list->cmd->tab[i]);
		i++;
	}
	free(list->cmd->tab);
	
}
