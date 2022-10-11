#include "minishell.h"

int	pipe_in_quote(char *line)
{
	int	i;

	i = 0;
	if (pipe_in_single_quote(line) == 0)
	{
		return (0);
	}
	while (line[i] != '\0')
	{
		if (line[i] == DOBBLE_QUOTE)
		{
			i = 0;
			while (line[i] != DOBBLE_QUOTE)
			{
				if (line[i] == '|')
				{
					//printf("pipe inside quote\n");
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

int	pipe_in_single_quote(char *line)
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
				if (line[i] == '|')
				{
					//printf("pipe inside quote\n");
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