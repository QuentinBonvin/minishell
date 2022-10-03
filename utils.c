#include "minishell.h"

int	string_search(char *line, char c)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == c)
			return (-1);
		i++;
	}
	return (0);
}
