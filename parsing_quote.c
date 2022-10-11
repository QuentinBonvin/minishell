#include "minishell.h"

int	only_one_simple_or_dobble_quote(char *line)
{
	int	i;
	int	nbr_simple_quote;
	int	nbr_dobble_quote;

	i = -1;
	nbr_simple_quote = 0;
	nbr_dobble_quote = 0;
	while (line[++i])
	{
		if (line[i] == DOBBLE_QUOTE)
		{
			if (quote_inside_dobble_quote(line) == -1)
				nbr_dobble_quote++;
		}
		if (line[i] == SIMPLE_QUOTE)
		{
			if (quote_inside_simple_quote(line) == -1)
				nbr_simple_quote++;
		}
	}
	if (nbr_dobble_quote == 1 || nbr_simple_quote == 1)
		return (-1);
	return (0);
}

int	quote_inside_dobble_quote(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == DOBBLE_QUOTE)
		{
			i = 0;
			while (line[i] != DOBBLE_QUOTE)
			{
				if (line[i] == DOBBLE_QUOTE || line[i] == SIMPLE_QUOTE)
				{
					return (0);
				}
				i++;
			}
			if (line[i] == DOBBLE_QUOTE)
				return (-1);
		}
		i++;
	}
	return (-1);
}

int	quote_inside_simple_quote(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == SIMPLE_QUOTE)
		{
			i = 0;
			while (line[i] != SIMPLE_QUOTE)
			{
				if (line[i] == DOBBLE_QUOTE || line[i] == SIMPLE_QUOTE)
				{
					return (0);
				}
				i++;
			}
			if (line[i] == SIMPLE_QUOTE)
				return (-1);
		}
		i++;
	}
	return (-1);
}
