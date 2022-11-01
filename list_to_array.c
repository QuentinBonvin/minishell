#include "minishell.h"

//we take the linked list and convert it to a char** per node

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
			tmp->tab = ft_split(tmp->content, '\"');
		else
			tmp->tab = ft_split(tmp->content, ' ');
		tmp = tmp->prev;
	}
	is_redir(list);
	tmp = curr;
	while (tmp)
	{
		i = -1;
		while (tmp->tab[++i])
			printf("tab: %s\n", tmp->tab[i]);
		tmp = tmp->prev;
	}
}

int	is_redir(t_shell *list)
{
	t_cmd	*curr;
	int		i;

	curr = list->head;
	i = 0;
	while(curr->tab[i])
	{
		if (curr->tab[i][0] == '>' && curr->tab[i][1] != '>')
		{
			list->redir_status = TRUE;
			simple_output(list, i);
		}
		if (curr->tab[i][0] == '>' && curr->tab[i][1] == '>')
		{
			list->redir_status = TRUE;
			// output_append(list, i);
			printf("output append\n");
		}
		if (curr->tab[i][0] == '<' && curr->tab[i][1] != '<')
			printf("input\n");
		if (curr->tab[i][0] == '<' && curr->tab[i][1] == '<')
			printf("heredoc\n");
		i++;
	}
	return (0);
}
