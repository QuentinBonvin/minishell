#include "minishell.h"

int	simple_output(t_cmd *curr, int i)
{
	// t_cmd	*curr;
	int		fd;

	fd = 0;

	printf("file = %s\n", curr->tab[i]);
	fd = open(curr->tab[i], O_CREAT | O_RDWR | O_TRUNC, 0644);
	printf("FD open: %d\n", fd);
	if (fd == -1)
	{
		perror("open: ");
		return (-1);
	}
	//if (curr->fd_out > 2)
	//	close(curr->fd_out);
	curr->fd_out = fd;
	delete_chev(curr, i);
	printf("redir fd_in = %d\n", curr->fd_in);
    printf("redir fd_out = %d\n", curr->fd_out);
	return (0);
}

// {
// 	dup2(file, STDOUT_FILENO);
// }