/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:27:35 by qbonvin           #+#    #+#             */
/*   Updated: 2022/11/18 16:23:57 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	simple_output(t_cmd *curr, int i)
{
	int	fd;

	fd = open(curr->tab[i], O_CREAT | O_WRONLY | O_TRUNC, 0644);
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
	fd = open(curr->tab[i], O_CREAT | O_WRONLY | O_APPEND, 0644);
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
	char	*delimiter;

	delimiter = curr->tab[i];
	pipe(fd);
	if (delimiter == NULL)
		return (0);
	own_heredocs_to_long(delimiter, NULL, fd, curr);
	delete_chev(curr, i);
	return (0);
}

void	own_heredocs_to_long(char *delimiter, char *line, int *fd, t_cmd *curr)
{
	while (1)
	{
		line = readline("heredoc> ");
		if (!line)
			break ;
		if (ft_strncmp(line, delimiter, ft_strlen(line)) != 0 || line[0] == 0)
		{
			ft_putendl_fd(line, fd[1]);
			free(line);
		}
		else
			break ;
	}
	free(line);
	close (fd[1]);
	if (curr->fd_in > 2)
		close (curr->fd_in);
	curr->fd_in = fd[0];
	return ;
}
