#include "minishell.h"

void	exec(t_shell *list, char **envp, char *line, t_env *env)
{
	t_cmd	*current;

	current = list->head;
	if (current->prev == NULL && (builtin(list, envp, line) != -1)
			&& (current->redir_status != TRUE))
	{
		exec_builtin(list, envp, line, env);
	}
	else
		exec_with_pipe(list, envp, line, env);
}

void	exec_with_pipe(t_shell *list, char **envp, char *line, t_env *env)
{
	char	**execute;
	int		i;
	t_cmd	*current;

    current = list->head;
    current->pid = 0;
    i = 0;
    execute = bins(current, list, envp, env);
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
                bins_execute(execute, list, envp, current);
            printf("bash: %s: command not found\n", current->tab[i]);
            exit(127);
        }
        current = current->prev;
    }
    free_split_path(execute);
    close_pipe(list);
    wait_pipe(list);
}

void    init_pipe(t_shell *list)
{
    int        fd[2];
    t_cmd    *current;

    current = list->head;
    // if (list == NULL)
    //     exit(EXIT_FAILURE);
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

void    close_pipe(t_shell *list)
{
    t_cmd     *current;

    current = list->head;
    while (current != NULL)
    {
        // printf("hello\n");
        if (current->fd_in > 2)
            close(current->fd_in);
        if (current->fd_out > 2)
            close(current->fd_out);
        current = current->prev;
    }
}

void    wait_pipe(t_shell *list)
{
    t_cmd *current;
    int     wstatus;

    current = list->head;
    while (current != NULL)
    {
        // printf("hello2\n");
        if (current->pid > 0)
        {
            waitpid(current->pid, &wstatus, 0);
            if (WIFEXITED(wstatus))
                g_exit_status = WEXITSTATUS(wstatus); 
        }
		current = current->prev;
    }
}
