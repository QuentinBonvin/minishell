#include "minishell.h"

void	bins(t_cmd *cmd, t_shell *list, char **envp)
{
	char	**split_path;
	char	*path;
	int		i;

	i = -1;
	path = search_env(list);
	split_path = ft_split(path, ':');
	split_path[0] = ft_substr(split_path[0], 5, ft_strlen(split_path[0]));
	while (split_path[++i])
	{
		split_path[i] = ft_strjoin(split_path[i], "/");
		// fprintf(stderr,"split_path[i] = %s\n", split_path[i]);
	}
	i = -1;
	while (split_path[++i])
	{
		split_path[i] = ft_strjoin(split_path[i], cmd->tab[0]);
			// fprintf(stderr,"split_path = %s\n", split_path[i]);

	}
	bins_execute(split_path, list, envp);
	free_split_path(split_path);
		// curr = curr->prev;
}

void	bins_execute(char **split_path, t_shell *list, char **envp)
{
		int 	i;
		t_cmd	*curr;


		i = 0;
		curr = list->head;
		while (split_path[i])
		{
			printf("curr->tab[0] = %s\n", curr->tab[0]);
			if (execve(split_path[i], &curr->tab[0], envp) == -1)
				i++;
			// curr = curr->prev;
		}
		// if (i == 9)
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
