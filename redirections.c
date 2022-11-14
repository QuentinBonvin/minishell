#include "minishell.h"

int	simple_output(t_cmd *curr, int i)
{
	int	fd;

	fd = 0;
	fd = open(curr->tab[i], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("open: ");
		return (-1);
	}
	if (curr->fd_out > 2)
		close(curr->fd_out);
	curr->fd_out = fd;
	delete_chev(curr, i);
	return (0);
}

int	dobble_output(t_cmd *curr, int i)
{
	int	fd;

	fd = 0;
	fd = open(curr->tab[i], O_CREAT | O_RDWR | O_APPEND, 0644);
	if (fd == -1)
	{
		perror("open: ");
		return (-1);
	}
	if (curr->fd_out > 2)
		close(curr->fd_out);
	curr->fd_out = fd;
	delete_chev(curr, i);
	return (0);
}

int	simple_input(t_cmd *curr, int i)
{
	int	fd;

	fd = 0;
	fd = open(curr->tab[i], O_RDONLY, 0644);
	if (fd == -1)
	{
		perror("open: ");
		return (-1);
	}
	if (curr->fd_out > 2)
		close(curr->fd_out);
	curr->fd_in = fd;
	delete_chev(curr, i);
	return (0);
}

int	own_heredocs(t_cmd *curr, int i)
{
	int		fd[2];
	char	*line;
	char	*delimiter;

	delimiter = curr->tab[i];
	pipe(fd);
	if (delimiter == NULL)
		return (0);
	while (1)
	{
		line = readline("heredoc> ");
		if (!line)
			break ;
		if (ft_strcmp(line, delimiter) != 0)
			ft_putendl_fd(line, fd[1]);
		else
			break ;
	}
	free(line);
	close (fd[1]);
	if (curr->fd_in > 2)
		close (curr->fd_in);
	curr->fd_in = fd[0];
	delete_chev(curr, i);
	return (0);
}
