#include "minishell.h"

int	mini_exit(t_shell *list, char *arg, char *line)
{
	if (arg == NULL)
	{
		free_cmd(list);
		free_env(list);
		free(line);
		// free(list->cmd->tab);
		exit (g_exit_status);
	}
	return (0);
}