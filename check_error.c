#include "minishell.h"

int	check_error(char *line)
{
	if (check_data_to_lst(line) == -1)
		return (-1);
	return (0);
}

int	check_data_to_lst(char *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (data[i])
	{
		j = i;
		i = is_quote(data, i);
		if (j != i)
			i++;
		if (after_is_quote(data, i) == -1)
		{
			printf("error parsing quote\n");
			return (-1);
		}
		if (data[i] == '|')
		{
			if ((is_double_pipe(data, i) == -1)
				|| (pipe_at_start_or_end(data) == -1
					|| check_space_beetween_pipe(data, i) == -1))
				return (-1);
		}
		if (data[i] == '\0')
			return (0);
		if (data[i] != '\'' && data[i] != '\"')
			i++;
	}
	return (0);
}
