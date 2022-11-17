#include "minishell.h"

t_shell	*check_line(char *line, t_shell *list, t_env *env)
{
	list->double_quote = 0;
	list->single_quote = 0;
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
			if (what_quote(tmp->tab[i]) == 1)
				tmp->tab[i] = ft_strtrim(tmp->tab[i], "\'");
			else if (what_quote(tmp->tab[i]) == 2)
				tmp->tab[i] = ft_strtrim(tmp->tab[i], "\"");
		}
		tmp = tmp->prev;
	}
}

void	delete_empty_tab(t_shell *list)
{
	t_cmd	*curr;
	int		i;

	curr = list->head;
	while (curr)
	{
		i = 0;
		swap_tab(curr->tab, i);
		curr = curr->prev;
	}
}

int	swap_tab(char **str, int i)
{
	int	j;

	while (str[i])
	{
		if (ft_strcmp(str[i], "") == 0)
		{
			free(str[i]);
			j = i + 1;
			while (str[j])
			{
				str[i] = str[j];
				i++;
				j++;
			}
		}
		i++;
	}
	if (j > 0)
		str[i - 1] = NULL;
	return (0);
}
