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
			tmp->tab = ft_split(tmp->content, '\"');
		else
			tmp->tab = ft_split(tmp->content, ' ');
		tmp = tmp->prev;
	}
	// is_redir(list);
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
	while (curr)
	{
		i = 0;
		while(curr->tab[i])
		{
			if (curr->tab[i][0] == '>' && curr->tab[i][1] != '>')
			{
				list->redir_status = TRUE;
				delete_chev(curr, i);
				simple_output(curr, i);
			}
			else if (curr->tab[i][0] == '>' && curr->tab[i][1] == '>')
			{
				list->redir_status = TRUE;
				// output_append(list, i);
				printf("output append\n");
			}
			else if (curr->tab[i][0] == '<' && curr->tab[i][1] != '<')
				printf("input\n");
			else if (curr->tab[i][0] == '<' && curr->tab[i][1] == '<')
				printf("heredoc\n");
			i++;
		}
		curr = curr->prev;
	}
	return (0);
}

void	delete_chev(t_cmd *curr, int i)
{
	int 	j;
	// t_cmd	*curr;

	printf("tab[i]: %s\n", curr->tab[i]);
	free(curr->tab[i]);
	// i = 0;
	j = i + 1;
	while (curr->tab[j])
	{
		curr->tab[i] = curr->tab[j];
		printf("%s\n", curr->tab[i]);
		i++;
		j++;
		// printf("%s\n", curr->tab[j]);
	}
	curr->tab[i] = NULL;
	// j = -1;
	// while (curr->tab[++j])
	// 	printf("new tab: %s\n", curr->tab[j]);

}