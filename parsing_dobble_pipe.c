#include "minishell.h"

int	pipe_at_start_or_end(char *line)
{
	int	j;

	j = ft_strlen(line);
	if (line[0] == '|' || line[j - 1] == '|')
	{
		printf("syntax error near unexpected token `|'\n");
		return (-1);
	}
	while(j > 0)
	{
		if (ft_isascii(line[j]))
			return (0);
		if (line[j] == ' ')
		{
			j--;
			if (line[j] == '|')
			{
				printf("syntax error near unexpected token `|'\n");
				return (-1);
			}
		}
		j--;
	}
	return (0);
}

int	is_dobble_pipe(char *line)
{
	int	i;
	int	nbr_quote;

	i = -1;
	nbr_quote = 0;

	while (line[++i])
		if ((line[i] == SIMPLE_QUOTE || line[i] == DOBBLE_QUOTE) && (pipe_in_quote(&line[i + 1]) == 0))
			nbr_quote++;
	i = -1;
	if (nbr_quote == 0)
	{
		while (line[++i])
		{
			if (line[i] == PIPE)
			{
				if (line[i + 1] == PIPE)
				{
					printf("there is dobble pipe\n");
					return (-1);
				}
			}
		}
	}
	return (0);
}


