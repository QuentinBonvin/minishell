#include "minishell.h"

int	check_quote(char *line, int position, char c)
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
