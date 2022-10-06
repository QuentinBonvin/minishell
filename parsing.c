#include "minishell.h"

int	parsing_line(char *line, t_shell *list)
{
	int			i;
	int			ret;

	i = 0;
	if (!(string_search(line, '\'') || string_search(line, '\"')))
	{
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
	if (parsing_line(line, list) == 0 && list->double_quote == 1)
		split_with_double_quote(line, list);
	if (parsing_line(line, list) == 0 && list->single_quote == 1)
		split_with_single_quote(line, list);
}

int	check_error(char *line)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(line);
	//printf("%d\n", len);
	if (line[0] == '|')
		return (-1);
	if (line[len - 1] == '|')
		return (-1);
	return (0);
}
