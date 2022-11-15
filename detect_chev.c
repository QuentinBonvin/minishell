#include "minishell.h"

int	detect_one_chev_input(int i, t_cmd *curr)
{
	if (curr->tab[i][0] == '>' && curr->tab[i][1] != '>'
		&& curr->tab[i] != NULL)
	{
		delete_chev(curr, i);
		simple_output(curr, i);
		return (0);
	}
	return (1);
}

int	detect_two_chev_input(int i, t_cmd *curr)
{
	if (curr->tab[i][0] == '>' && curr->tab[i][1] == '>'
		&& curr->tab[i] != NULL)
	{
		delete_chev(curr, i);
		dobble_output(curr, i);
		return (0);
	}
	return (1);
}

int	detect_one_chev_output(int i, t_cmd *curr)
{
	if (curr->tab[i][0] == '<' && curr->tab[i][1] != '<'
		&& curr->tab[i] != NULL)
	{
		delete_chev(curr, i);
		simple_input(curr, i);
		return (0);
	}
	return (1);
}

int	detect_two_chev_output(int i, t_cmd *curr)
{
	if (curr->tab[i][0] == '<' && curr->tab[i][1] == '<'
		&& curr->tab[i] != NULL)
	{
		delete_chev(curr, i);
		own_heredocs(curr, i);
		return (0);
	}
	return (1);
}
