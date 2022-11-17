#include "minishell.h"

int	is_redir(t_shell *list)
{
	t_cmd	*curr;
	int		i;

	curr = list->head;
	while (curr)
	{
		curr->redir_status = 0;
		i = 0;
		while (curr->tab[i])
		{
			if (detect_chev(i, curr) == -1)
				i++;
		}
		curr = curr->prev;
	}
	return (0);
}

int	detect_chev(int i, t_cmd *curr)
{
	if (detect_one_chev_input(i, curr) == 0)
	{
		curr->redir_status = 1;
		return (0);
	}
	else if (detect_two_chev_input(i, curr) == 0)
	{
		curr->redir_status = 1;
		return (0);
	}
	else if (detect_one_chev_output(i, curr) == 0)
	{
		curr->redir_status = 1;
		return (0);
	}
	else if (detect_two_chev_output(i, curr) == 0)
	{
		curr->redir_status = 1;
		return (0);
	}
	return (-1);
}

void	delete_chev(t_cmd *curr, int i)
{
	int		j;

	free(curr->tab[i]);
	j = i + 1;
	while (curr->tab[j])
	{
		curr->tab[i] = curr->tab[j];
		i++;
		j++;
	}
	curr->tab[i] = NULL;
}
