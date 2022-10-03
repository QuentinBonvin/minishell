#include "minishell.h"

int	parsing_line(char *line)
{
	int			i;
	int			ret;

	i = 0;
	if (!(string_search(line, '\'') || string_search(line, '\"')))
	{
		split_with_pipe(line);
		return (-1);
	}
	while (line[i])
	{
		if (line[i] == SIMPLE_QUOTE || line[i] == DOBBLE_QUOTE)
		{
			if (pipe_in_quote(&line[i + 1]) == -1)
				return (-1);
			ret = check_quote(line, i, line[i]);
			if (ret == -1)
			{
				printf("error\n");
				return (-1);
			}
			i = ret;
		}
		i++;
	}
	return (0);
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