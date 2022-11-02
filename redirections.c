#include "minishell.h"

void	simple_output(t_shell *list, int i)
{
	t_cmd	*curr;
	int		fd;
	char	*file;

	fd = 0;
	file = NULL;
	curr = list->head;
	i += 1;
	if (curr->tab[1] != '>')
	{
		file = curr->tab[i];
	}
	printf("file: %s\n",file);
	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	printf("are we here");
	write(3, &curr->tab[1], ft_strlen(curr->tab[1]));
	write(fd, "\n", 1);
	close(fd);
}

// {
// 	dup2(file, STDOUT_FILENO);
// }