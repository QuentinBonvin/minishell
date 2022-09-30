
#include "minishell.h"

char	*check_quote(char *line)
{
	int		i;
	char *tmp;
	char *tmp2;


	tmp = malloc(sizeof(char*) * ft_strlen(line));
	tmp2 = malloc(sizeof(char*) * ft_strlen(line));
	i = 0;
	while (line[i])
	{
		if (line[i] == DOBBLE_QUOTE)
		{
			tmp = (ft_substr(line, 0, (i)));
			tmp2 = (ft_substr(line, (i + 1), (ft_strlen(line))));
		}
		i++;
	}
	printf("%s\n", tmp);
	printf("%s\n", tmp2);
	return (0);
}

int	nbr_quote(char *line)
{
	int i;
	int	nbr_quote;

	nbr_quote = 0;
	i = 0; 
	while (line[i])
	{
		if (line[i] == DOBBLE_QUOTE)
			nbr_quote++;
		if (line[i] == SIMPLE_QUOTE)
			nbr_quote++;
		i++;
	}
	return (nbr_quote);
}

int	dobble_quote(char *line)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (check_if_another_dobble_quote(&line[i]))
			break ;
		i++;
		j++;
	}
	new_line = ft_substr(line, 0, ft_strlen(line) - 1);
	printf("%s\n", new_line);
	return (0);
}

int	check_if_another_dobble_quote(char *line)
{
	int	i;

	i = 0;
	if (line[i] == DOBBLE_QUOTE)
		return (1);
	return (0);
}
