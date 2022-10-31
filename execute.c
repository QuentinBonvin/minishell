#include "minishell.h"

void	exec(t_shell *list, char **envp, char *line)
{
	t_cmd	*current;

	current = list->head;
	if (current->prev == NULL)
	{
		builtin(list, envp, line);
	}
	else
		exec_with_pipe(list, envp, line);
}

void	exec_with_pipe(t_shell *list, char **envp, char *line)
{
	(void)list;
	(void)envp;
	(void)line;
		printf("execution with pipe\n");
		//builtin(list, envp, line);
}