#include "minishell.h"

int	parsing_line(char *line, t_shell *list)
{
	int			i;
	int			ret;

	i = 0;
	if (!string_search(line, '\'') || string_search(line, '\"'))
	{
		split_with_pipe(line, list);
		return (-1);
	}
	while (line[i])
	{
		if (line[i] == SIMPLE_QUOTE)
		{
			ret = check_quote(line, i, line[i]);
			if (ret == -1)
			{
				printf("error\n");
				return (-1);
			}
			i = ret;
		list->single_quote = 1;
		}
		if (line[i] == DOBBLE_QUOTE)
		{
			ret = check_quote(line, i, line[i]);
			if (ret == -1)
			{
				printf("error\n");
				return (-1);
			}
			i = ret;
			list->double_quote = 1;
		}
		i++;
	}
	return (0);
}

void	check_line(char *line, t_shell *list)
{
	if (parsing_line(line, list) == 0 && list->double_quote == 1)
		split_with_double_quote(line, list);
	if (parsing_line(line, list) == 0 && list->single_quote == 1)
		split_with_single_quote(line, list);
}

int	check_error(char *line)
{
	if (pipe_at_start_or_end(line) == -1)
		return (-1);
	if (only_one_simple_or_dobble_quote(line) == -1)
		return (-1);
	if (is_dobble_pipe(line) == -1)
		return (-1);
	if (space_after_pipe(line) == -1)
		return (-1);
	return (0);
}

int	pipe_at_start_or_end(char *line)
{
	int	j;

	j = ft_strlen(line);
	if (line[0] == '|' || line[j] == '|')
	{
		printf("syntax error near unexpected token `|'\n");
		return (-1);
	}
	while(j > 0)
	{
		if (ft_isalpha(j) == -1 || ft_isdigit(j) == -1)
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

int	only_one_simple_or_dobble_quote(char *line)
{
	int	i;
	int	nbr_simple_quote;
	int	nbr_dobble_quote;

	i = 0;
	nbr_simple_quote = 0;
	nbr_dobble_quote = 0;
	while (line[i])
	{
		if (line[i] == DOBBLE_QUOTE)
			nbr_dobble_quote++;
		if (line[i] == SIMPLE_QUOTE)
			nbr_simple_quote++;
		i++;
	}
	if (nbr_dobble_quote == 1 || nbr_simple_quote == 1)
	{
		printf("error, only 1 simple or 1 dobble quote\n");
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
		if (((line[i] == SIMPLE_QUOTE || line[i] == DOBBLE_QUOTE)) && (pipe_in_quote(&line[i + 1]) == 0))
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

int	space_after_pipe(char *line)
{
	int	i;
	int	j;
	int	nbr_pipe;
	i = -1;

	nbr_pipe = nbr_pipe_in_string(line);
	if (nbr_pipe > 1)
	{
		while (line[++i])
		{
			if (line[i] == PIPE && pipe_in_quote(&line[i]) == -1)
			{
				j = i + 1;
				while (line[j] != PIPE)
				{
					if (line[j] == ' ')
					{
						printf("space beetween pipe\n");
						return (-1);
					}
					j++;
				}
			}
		}
	}
	return (0);
}

int	nbr_pipe_in_string(char *line)
{
	int	i;
	int	j;
	int	nbr_pipe;

	nbr_pipe = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '|')
		{
			nbr_pipe++;
			j = i + 1;
			while (line[j])
			{
				if (line[j] == '|')
					nbr_pipe++;
				j++;
			}
		}
		i++;
	}
	return (nbr_pipe);
}
