
#include "minishell.h"

int check_quote(char *line, int position, char c)
{
	int	i;
	int	j;

	i = 0;
	j = position + 1;
	while (line[j])
	{
		if (line[j] == c)
			return (j);
		j++;
	}
	return (-1);
}

int	pipe_in_quote(char *line)
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
				if (line[i] == '|')
				{
					printf("pipe inside quote\n");
					return (0);
				}
				i++;
			}
		}
		i++;
	}
	return (-1);
}