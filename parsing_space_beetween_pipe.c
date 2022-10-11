#include "minishell.h"

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
				j = i;
				while (line[j] != PIPE)
				{
					if (check_if_letter_beetween_pipe(&line[j]) == 0)
						return (0);
					if (line[j] == ' ')
						return (-1);
					j++;
				}
			}
		}
	}
	return (0);
}

int	check_if_letter_beetween_pipe(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '|')
	{
		if (ft_isalpha(line[i]) == 1 || ft_isdigit(line[i]) == 1)
			return (0);
		i++;
	}
	return (-1);
}
