#include "minishell.h"

void	ft_split_space(char *line, char c, t_cmd *curr)
{
	size_t	i;
	int		j;
	size_t	index;

	i = 0;
	j = 0;
	index = -1;
	curr->tab = ft_calloc(sizeof (char *), ft_set(line, ' ') + 1);
	while (i <= ft_strlen(line))
	{
		while (line[i] && line[i] == c)
		{
			i = is_quote(line, i);
			i++;
		}
		index = i;
		while (line[i] && line[i] != c)
		{
			i = is_quote(line, i);
			i++;
		}
		if (index != i)
			curr->tab[j++] = ft_substr(line, index, i - index);
		i++;
	}
}

int	ft_set(char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}
