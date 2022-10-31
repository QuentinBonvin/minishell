#include "minishell.h"

void	redir(t_shell *list)
{
	t_cmd	*curr;
	int		fd;
	int		i;
	char	*file;

	fd = 0;
	i = 0;
	curr = list->head;
	while(curr->tab[i])
	{
		if (curr->tab[i][0] == '>' && curr->tab[i][1] != '>')
		{
			i += 1;
			file = curr->tab[i];
			i += 2;
			printf("file: %s\n",file);
			fd = open(file, O_WRONLY | O_CREAT, 0777);
			write(3, &curr->tab[i], ft_strlen(curr->tab[i]));
		}
		if (curr->tab[i][0] == '>' && curr->tab[i][1] != '>')
		{
			i += 1;
			file = curr->tab[i];
			printf("file: %s\n",file);
			fd = open(file, O_WRONLY | O_CREAT, 0777);
		}
		i++;
	}
}

// void	double_sign(t_shell * list)
// {
// 	int		fd;


// 	file = curr->tab[i];
// 	fd = open(file, O_WRONLY | O_CREAT, 0777);

// }