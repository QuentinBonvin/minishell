#include "minishell.h"

char	**bins(t_cmd *cmd, t_env *env)
{
	char	**split_path;
	char	*path;
	char	*pathtmp;
	int		i;

	i = -1;
<<<<<<< HEAD
	path = search_env(env);
	split_path = ft_split(path, ':');
	//free(split_path_tmp);

	pathtmp = split_path[0];
	split_path[0] = ft_substr(split_path[0], 5, ft_strlen(split_path[0]));
	free(pathtmp);
	//free_split_path(split_path_tmp);
	// printf("address of split_path[0] =\n%p\n", split_path[0]);
=======
	if (search_env(env) == NULL)
	{
		printf("minishell: %s: command not found \n", cmd->tab[0]);
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
>>>>>>> 2f1230cb5d523d1c179a6d41552edd6b576ce564
	return (split_path);
}

void	bins_execute(char **split_path, char **envp, t_cmd *cmd)
{
	int		i;
	int		y;
	char	*tmp;
	char	*tmp2;
	t_cmd	*curr;

	i = 0;
	y = -1;
	curr = cmd;
	while (split_path[++y])
	{
		tmp = ft_strjoin(split_path[y], "/");
		tmp2 = ft_strjoin(tmp, curr->tab[0]);
		free (tmp);
		if (!access(tmp2, X_OK))
		{
			if (execve(tmp2, curr->tab, envp) == -1)
			{
				i++;
				free(tmp2);
				g_exit_status = 1;
			}
		}
	}
	check_command_not_found(i, tmp2, curr);
	free_split_path(split_path);
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
