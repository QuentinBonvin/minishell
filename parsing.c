#include "minishell.h"

int	parsing_line(char *line, t_shell *list)
{
	int			i;
	int			ret;

	i = 0;
	if (!(string_search(line, '\'') || string_search(line, '\"')))
	{
		// if (
		split_with_pipe(line, list);
		return (-1);
	}
	while (line[i])
	{
		if (line[i] == SIMPLE_QUOTE)
		{
			// if (pipe_in_quote(&line[i + 1]) == -1)
			// 	return (-1);
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
			// if (pipe_in_quote(&line[i + 1]) == -1)
			// 	return (-1);
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
	if (check_error(line))
	{
		printf("error\n");
		//return (0);
	}
	printf("%s\n", line);
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
	return (0);
}

int	pipe_at_start_or_end(char *line)
{

	int	len;
	int	i;

	i = 0;
	len = ft_strlen(line);
	if (line[0] == '|')
	{
		printf("syntax error near unexpected token `|'\n");
		return (-1);
	}
	if (line[len - 1] == '|')
	{
		printf("error\n");
		return (-1);
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
