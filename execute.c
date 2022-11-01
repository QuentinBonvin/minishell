#include "minishell.h"

void	exec(t_shell *list, char **envp, char *line)
{
	t_cmd	*current;

	current = list->head;
	if (current->prev == NULL && (builtin(list, envp, line) != -1))
	{
		exec_builtin(list, envp, line);
	}
	else
		exec_with_pipe(list, envp, line);
}

void    exec_with_pipe(t_shell *list, char **envp, char *line)
{
    (void)line;
    int     i;
    t_cmd    *current;
    current = list->head;
    current->pid = 0;
    i = 0;
    
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
			if (builtin(list, envp, line) == -1)
            {
            	bins(current, list, envp);
            }
            exit(0);
        }
        current = current->prev;
    }
    // printf("multiple pipe\n");
    close_pipe(list);
    wait_pipe(list);
    //builtin(list, envp, line);
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

    current = list->head;
    while (current != NULL)
    {
        // printf("hello2\n");
        if (current->pid > 0)
            waitpid(current->pid, NULL, 0);
        current = current->prev;
    }
}
