#include "minishell.h"

char	**bins(t_cmd *cmd, t_shell *list, char **envp)
{
	char	**split_path;
	char	*path;
	char	*pathtmp;
	(void)envp;
	(void)cmd;
	int		i;

	i = -1;
	path = search_env(list);
	// printf("path = %s\n", path);
	split_path = ft_split(path, ':');
	pathtmp = split_path[0];
	split_path[0] = ft_substr(split_path[0], 5, ft_strlen(split_path[0]));
	free(pathtmp);
	return (split_path);
	// while (split_path[++i])
	// {
	// 	split_path[i] = ft_strjoin(split_path[i], "/");
	// 	// fprintf(stderr,"split_path[i] = %s\n", split_path[i]);
	// }
	// i = -1;
	// while (split_path[++i])
	// {
	// 	split_path[i] = ft_strjoin(split_path[i], cmd->tab[0]);
	// 		// fprintf(stderr,"split_path = %s\n", split_path[i]);

	// }
	// i = 0;
	// while (split_path[i])
	
	// 	i++;
	// }
	
	// free_split_path(split_path);
}

void	bins_execute(char **split_path, t_shell *list, char **envp, t_cmd *cmd)
{
		int 	i;
		int		y;
		char *tmp;
		char *tmp2;
		t_cmd	*curr;
		(void)list;

		i = 0;
		y = 0;
		curr = cmd;
		while (split_path[y])
		{
			tmp = ft_strjoin(split_path[y], "/");
			tmp2 = ft_strjoin(tmp, curr->tab[0]);
			free (tmp);
			if (execve(tmp2, curr->tab, envp) == -1)
			free(tmp2);
			y++;
		}
		
		// 	ft_printf(list->tail->tab[0], "%s");
		// 	ft_printf(": command not found\n");
	// free_split_path(split_path);
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
