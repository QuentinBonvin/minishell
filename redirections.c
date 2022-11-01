#include "minishell.h"

void	simple_output(t_shell *list, int i)
{
	t_cmd	*curr;
	int		fd;
	char	*file;

	fd = 0;
	curr = list->head;
	i += 1;
	file = curr->tab[i];
	printf("file: %s\n",file);
	file = ft_strjoin(file, ".txt");
	fd = open(file, O_WRONLY | O_CREAT, 0644);
	write(fd, "\n", 1);
	close(fd);
}

// {
// 	dup2(file, STDOUT_FILENO);
// }