#include "minishell.h"

t_shell	*check_line(char *line, t_shell *list, t_env *env)
{
	list->double_quote = 0;
	list->single_quote = 0;
	// printf("quote: %d\n", list->double_quote);
	// printf("quote: %d\n", list->double_quote);

	ft_split2(line, '|', list);
	list_to_array(list, env);
	delete_empty_tab(list);
	trim_quote(list);
	return (list);
}

void	trim_quote(t_shell *list)
{
	t_cmd	*tmp;
	int		i;

	tmp = list->head;
	while (tmp)
	{
		i = -1;
		while (tmp->tab[++i])
		{
			if (list->single_quote == 1)
				tmp->tab[i] = ft_strtrim(tmp->tab[i], "\'");
			else if (list->double_quote == 1)
			{
				tmp->tab[i] = ft_strtrim(tmp->tab[i], "\"");
				//printf("tmp->tab[i] after trim = %s\n", tmp->tab[i]);
			}
		}
		// i = -1;
		tmp = tmp->prev;
	}
}

void	delete_empty_tab(t_shell *list)
{
	t_cmd	*curr;
	int		i;
	int		j;
	curr = list->head;
	while (curr)
	{
		i = 0;
		while(curr->tab[i])
		{
			//printf("curr->tab[%d] = %s\n", i, curr->tab[i]);
			if (ft_strcmp(curr->tab[i], "") == 0)
			{
				free(curr->tab[i]);
				j = i + 1;
				while (curr->tab[j])
				{
					curr->tab[i] = curr->tab[j];
					i++;
					j++;
				}
			}
			i++;
		}
		if (i > 0)
			curr->tab[i] = NULL;


		curr = curr->prev;
	}

}
