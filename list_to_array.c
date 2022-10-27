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
			tmp->tab = ft_split(tmp->content, '\'');
		else if (string_search(tmp->content, '\"') == -1)
			tmp->tab = ft_split(tmp->content, '\"');
		else
			tmp->tab = ft_split(tmp->content, ' ');
		tmp = tmp->prev;
	}
	tmp = curr;
	while (tmp)
	{
		i = -1;
		while (tmp->tab[++i])
			printf("tab: %s\n", tmp->tab[i]);
		tmp = tmp->prev;
	}
}
