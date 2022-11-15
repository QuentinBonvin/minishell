#include "minishell.h"

t_shell	*check_line(char *line, t_shell *list, t_env *env)
{
	list->double_quote = 0;
	list->single_quote = 0;
	ft_split2(line, '|', list);
	list_to_array(list, env);
	trim_quote(list);
	return (list);
}

void	trim_quote(t_shell *list)
{
	t_cmd	*tmp;
	int		i;

	tmp = list->head;
	i = -1;
	while (tmp)
	{
		while (tmp->tab[++i])
		{
			if (list->single_quote == 1)
				tmp->tab[i] = ft_strtrim(tmp->tab[i], "\'");
			else if (list->double_quote == 1)
				tmp->tab[i] = ft_strtrim(tmp->tab[i], "\"");
		}
		i = -1;
		tmp = tmp->prev;
	}
}
