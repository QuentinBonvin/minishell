#include "minishell.h"

int	pipe_at_start_or_end(char *line)
{
	int	i;
	int	nbr_space;

	i = 0;
	nbr_space = 0;
	if (first_char_is_pipe(line) == -1 || last_char_is_pipe(line) == -1)
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

int	last_char_is_pipe(char *line)
{
	int	i;
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
		return (-1);
	return (0);
}

int	first_char_is_pipe(char *line)
{
	if (line[0] == PIPE)
	{
		printf("syntax error near unexpected token `|'\n");
		return (-1);
	}
	return (0);
}

int	is_double_pipe(char *data, int i)
{
	if (data[i + 1] == PIPE)
		return (-1);
	return (0);
}

int	check_space_beetween_pipe(char *data, int i)
{
	int	find_char;

	find_char = 0;
	i++;
	while (data[i] != PIPE)
	{
		if (data[i] == '\0')
			break ;
		if (ft_isalpha(data[i]) == 1 || ft_isdigit(data[i]) == 1)
			find_char++;
		i++;
	}
	if (find_char == 0)
		return (-1);
	return (0);
}
