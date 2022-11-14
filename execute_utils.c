#include "minishell.h"

void	wait_pipe(t_shell *list)
{
	t_cmd	*current;
	int		wstatus;

	current = list->head;
	while (current != NULL)
	{
		if (current->pid > 0)
		{
			waitpid(current->pid, &wstatus, 0);
			if (WIFEXITED(wstatus))
				g_exit_status = WEXITSTATUS(wstatus);
		}
		current = current->prev;
	}
}

int	command_not_found(t_cmd *curr, char **envp)
{
	int	i;

	i = 0;
	if (execve(curr->tab[0], &curr->tab[i], envp) == -1)
		i++;
	if (i == 0)
	{
		return (-1);
	}
	return (0);
}
