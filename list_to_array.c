#include "minishell.h"

void	list_to_array(t_shell *list)
{
	t_cmd	*curr;
	t_cmd	*tmp;
	int		i;

	i = 0;
	curr = list->head;
	tmp = curr;
	while (tmp != NULL)
	{
		if (string_search(tmp->content, '\'') == -1)
		{
			list->single_quote = 1;
			tmp->tab = ft_split(tmp->content, '\'');
		}
		else if (string_search(tmp->content, '\"') == -1)
		{
			list->double_quote = 1;
			tmp->tab = ft_split(tmp->content, '\"');
		}
		else
			tmp->tab = ft_split(tmp->content, ' ');
		tmp = tmp->prev;
	}
	tmp = curr;
	find_dollar(list);
	// while (tmp)
	// {
	// 	i = -1;
	// 	while (tmp->tab[++i])
	// 		printf("tab: %s\n", tmp->tab[i]);
	// 	tmp = tmp->prev;
	// }
}

void	find_dollar(t_shell *list)
{
	t_cmd	*curr;
	int		i;
	char	*tmp;

	curr = list->head;
	while (curr)
	{
		i = 0;
		while (curr->tab[i])
		{
			if (curr->tab[i][0] == '$' && list->single_quote == 0)
			{
				tmp = ft_substr(curr->tab[i], (1), ft_strlen(curr->tab[i]));
				tmp = dollar_var(list, tmp);
				free(curr->tab[i]);
				curr->tab[i] = tmp;
			}
			i++;
		}
		curr = curr->prev;
	}
}

int	is_redir(t_shell *list)
{
	t_cmd	*curr;
	int		i;

	curr = list->head;
	while (curr)
	{
		i = 0;
		while(curr->tab[i])
		{
			if (curr->tab[i][0] == '>' && curr->tab[i][1] != '>' && curr->tab[i] != NULL)
			{
				curr->redir_status = TRUE;
				delete_chev(curr, i);
				simple_output(curr, i);
			}
			else if (curr->tab[i][0] == '>' && curr->tab[i][1] == '>' && curr->tab[i] != NULL)
			{
				curr->redir_status = TRUE;
				delete_chev(curr, i);
				dobble_output(curr, i);
			}
			else if (curr->tab[i][0] == '<' && curr->tab[i][1] != '<' && curr->tab[i] != NULL)
			{
				delete_chev(curr, i);
				simple_input(curr, i);
			}
			else if (curr->tab[i][0] == '<' && curr->tab[i][1] == '<' && curr->tab[i] != NULL)
			{
				delete_chev(curr, i);
				own_heredocs(curr, i);
			}
			else
				i++;
		}
		curr = curr->prev;
	}
	return (0);
}

void	delete_chev(t_cmd *curr, int i)
{
	int 	j;
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

// int	is_a_chevron(t_cmd *curr, int i)
// {
// 	if (curr->tab[i][0] == '>' && curr->tab[i][1] != '>' && curr->tab[i + 1] != NULL)
// 	{
// 		curr->redir_status = TRUE;
// 		delete_chev(curr, i);
// 		simple_output(curr, i);
// 		return (0);
// 	}
// 	else if (curr->tab[i][0] == '>' && curr->tab[i][1] == '>' && curr->tab[i + 1] != NULL)
// 	{
// 		curr->redir_status = TRUE;
// 		delete_chev(curr, i);
// 		dobble_output(curr, i);
// 		return (0);
// 	}
// 	else if (curr->tab[i][0] == '<' && curr->tab[i][1] != '<' && curr->tab[i + 1] != NULL)
// 	{
// 		delete_chev(curr, i);
// 		simple_input(curr, i);
// 		return (0);
// 	}
// 	else if (curr->tab[i][0] == '<' && curr->tab[i][1] == '<' && curr->tab[i + 1] != NULL)
// 	{
// 		delete_chev(curr, i);
// 		own_heredocs(curr, i);
// 		return (0);
// 	}
// 	return (1);
// }
