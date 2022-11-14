#include "minishell.h"

int	is_redir(t_shell *list)
{
	t_cmd	*curr;
	int		i;

	curr = list->head;
	curr->redir_status = 0;
	while (curr)
	{
		i = 0;
		while (curr->tab[i])
		{
            detect_chev(i, curr);
			i++;
		}
		curr = curr->prev;
	}
	return (0);
}

void	detect_chev(int i, t_cmd *curr)
{
	if (curr->tab[i][0] == '>' && curr->tab[i][1] != '>'
		&& curr->tab[i] != NULL)
	{
		curr->redir_status = 1;
		delete_chev(curr, i);
		simple_output(curr, i);
	}
	else if (curr->tab[i][0] == '>' && curr->tab[i][1] == '>'
		&& curr->tab[i] != NULL)
	{
		curr->redir_status = 1;
		delete_chev(curr, i);
		dobble_output(curr, i);
	}
	else if (curr->tab[i][0] == '<' && curr->tab[i][1] != '<'
		&& curr->tab[i] != NULL)
	{
		curr->redir_status = 1;
		delete_chev(curr, i);
		simple_input(curr, i);
	}
	else if (curr->tab[i][0] == '<' && curr->tab[i][1] == '<'
		&& curr->tab[i] != NULL)
	{
		curr->redir_status = 1;
		delete_chev(curr, i);
		own_heredocs(curr, i);
	}
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
