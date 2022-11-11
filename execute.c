#include "minishell.h"

void	exec(t_shell *list, char **envp, char *line, t_env *env)
{
	t_cmd	*current;

	current = list->head;
	signal(SIGINT, handle_sigquit);
	signal(SIGQUIT, handle_sigquit);
	if (current->prev == NULL && (builtin(list, envp, line) != -1)
		&& (current->redir_status != TRUE))
	{
		exec_builtin(list, envp, line, env);
	}
	else
	{
		exec_with_pipe(list, envp, line, env);
	}
}

void	exec_with_pipe(t_shell *list, char **envp, char *line, t_env *env)
{
	t_cmd	*current;
	char	**execute;

	current = list->head;
	current->pid = 0;
	execute = NULL;
	while (current != NULL)
	{
		current->pid = fork();
		if (current->pid == 0)
		{
			if (current->fd_out > 2)
				dup2(current->fd_out, STDOUT_FILENO);
			if (current->fd_in > 2)
				dup2(current->fd_in, STDIN_FILENO);
			close_pipe(list);
			if (exec_builtin(list, envp, line, env) == -1)
			{
				if (command_not_found(execute, current, envp) != -1)
				{
					if (bins(current, env) != NULL)
					{
						execute = bins(current, env);
						bins_execute(execute, envp, current);
					}
				}
			}
			exit(0);
		}
		current = current->prev;
	}
	if (execute != NULL)
		free_split_path(execute);
	close_pipe(list);
	wait_pipe(list);
}

void	init_pipe(t_shell *list)
{
	int		fd[2];
	t_cmd	*current;

	current = list->head;
	current->fd_in = 0;
	while (current->prev != NULL)
	{
		pipe(fd);
		current->fd_out = fd[1];
		current->prev->fd_in = fd[0];
		current = current->prev;
	}
	current->fd_out = 1;
	current = list->head;
	while (current)
	{
		current = current->prev;
	}
}

void	close_pipe(t_shell *list)
{
	t_cmd	*current;

	current = list->head;
	while (current != NULL)
	{
		if (current->fd_in > 2)
			close(current->fd_in);
		if (current->fd_out > 2)
			close(current->fd_out);
		current = current->prev;
	}
}

void	wait_pipe(t_shell *list)
{
	t_cmd	*current;

	current = list->head;
	while (current != NULL)
	{
		if (current->pid > 0)
			waitpid(current->pid, NULL, 0);
		current = current->prev;
	}
}

int	command_not_found(char **cmd, t_cmd *curr, char **envp)
{
	(void)cmd;
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
