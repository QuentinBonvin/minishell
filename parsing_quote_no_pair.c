#include "minishell.h"

int	quote_have_no_pair(char *line)
{
	int	i;

	i = 0;
	if (check_if_dobble_quote_is_pair(line) == -1 && check_if_single_quote_is_pair(line) == -1)
		return (-1);
	return (0);
}

int	check_if_dobble_quote_is_pair(char *line)
{
	int	i;
	int	dobble_quote;
	int	simple_quote;

	dobble_quote = 0;
	simple_quote = 0;
	i = 0;
	while (line[i])
	{
		if ((line[i] == DOBBLE_QUOTE) && quote_inside_dobble_quote(&line[i + 1]) == -1)
		{
			dobble_quote++;
		}
		i++;
	}
	if (dobble_quote == 0 || dobble_quote % 2 == 0)
	{
		return (0);
	}
	return (-1);
}

int	check_if_single_quote_is_pair(char *line)
{
	int	i;
	int	dobble_quote;
	int	simple_quote;

	dobble_quote = 0;
	simple_quote = 0;
	i = 0;
	while (line[i])
	{
		if ((line[i] == DOBBLE_QUOTE) && quote_inside_simple_quote(&line[i + 1]) == -1)
		{
			simple_quote++;
		}
		i++;
	}
	if (simple_quote == 0 || simple_quote % 2 == 0)
	{
		return (0);
	}
	return (-1);
}
