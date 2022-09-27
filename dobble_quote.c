#include "minishell.h"

int	check_quote(char *line)
{
	int	i;

	i = 0;

	if (line[i] == DOBBLE_QUOTE)
	{
		dobble_quote(&line[i + 1]);
		return (1);
	}
	return (0);
}

int	dobble_quote(char *line)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (check_if_another_dobble_quote(&line[i]))
			break ;
		i++;
		j++;
	}
	new_line = ft_substr(line, 0, ft_strlen(line) - 1);
	printf("%s\n", new_line);
	return (0);
}

int	check_if_another_dobble_quote(char *line)
{
	int	i;

	i = 0;
	if (line[i] == DOBBLE_QUOTE)
		return (1);
	return (0);
}
