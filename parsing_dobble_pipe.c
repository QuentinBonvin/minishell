#include "minishell.h"

int	pipe_at_start_or_end(char *line)
{
	int	i;
	int	nbr_space;

	i = 0;
	nbr_space = 0;
	if (/*first_char_is_pipe(line) == -1 || */last_char_is_pipe(line) == -1)
		return (-1);
	while (line[i] != PIPE)
	{
		if (line[i] == ' ')
		{
			nbr_space++;
			i++;
		}
		else
			i++;
	}
	if (i == nbr_space)
	{
		printf("syntax error near unexpected token `|'\n");
		return (-1);
	}
	return (0);
}

int last_char_is_pipe(char *line)
{
	int i;
	int	j;
	int	nbr_space;

	i = ft_strlen(line);
	i = i - 1;
	j = 0;
	nbr_space = 0;
	while (line[i] != PIPE)
	{
		if (line[i] == ' ')
		{
			nbr_space++;
			j++;
			i--;
		}
		else
			return (0);
	}
	if (j == nbr_space)
	{
		printf("only space after last pipe\n");
		return (-1);
	}
	return (0);
}

int first_char_is_pipe(char *line)
{
	if (line[0] == PIPE)
	{
		printf("syntax error near unexpected token `|'\n");
		return (-1);
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


