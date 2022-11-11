#include "minishell.h"

void	ft_split2(char const *line, char c, t_shell *list)
{
	size_t	i;
	int		index;

	i = 0;
	index = -1;
	while (i <= ft_strlen(line))
	{
		i = ft_split2_too_long(line, i);
		if (line[i] != c && index < 0)
			index = i;
		else if ((line[i] == c || i == ft_strlen(line)) && index >= 0)
		{
			if ((line[0] == 34 || line[0] == 39) && list->tail == NULL)
				index = 0;
			list->token = ft_substr(line, index, (i - index));
			if (list->tail == NULL)
				start_stack(&list->head, &list->tail, list->token);
			else
				insert_beginning(&list->tail, list->token);
			index = -1;
		}
		i++;
	}
}

int	ft_split2_too_long(const char *line, int i)
{
	if (line[i] == '\"')
	{
		i++;
		while (line[i] != '\0' && line[i] != '"')
			i++;
	}
	else if (line[i] == '\'')
	{
		i++;
		while (line[i] != '\0' && line[i] != '\'')
			i++;
	}
	return (i);
}
