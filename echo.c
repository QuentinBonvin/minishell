#include "minishell.h"

void	mini_echo(t_shell *list, char *command)
{
	int		option;
	int		i;
	t_cmd	*curr;

	curr = list->head;
	i = -1;
	option = 0;
	i = ft_find_sign(command);
	while (command[i] && (command[i + 1] == 'n'))
	{
		option = 1;
		i++;
	}
	while (curr->prev->content != NULL)
	{
		ft_putstr(curr->prev->content);
		curr = curr->prev;
	}
	if (option == 1)
		return ;
	else
		write(1, "\n", 1);
}

int	ft_find_sign(char *command)
{
	int	i;

	i = 0;
	while (command[++i])
	{
		if (command[i] == '-')
			break ;
	}
	return (i);
}
