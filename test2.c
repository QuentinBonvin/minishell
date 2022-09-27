#include "minishell.h"

unsigned int	is_delim(char c, char *delim)
{
	while (*delim != '\0')
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

char	*my_strtok(char *str, char *delim)
{
	static char	*tmp;

	if (!str)
		str = tmp;
	if (!str)
		return (NULL);
	while (1)
	{
		if (is_delim(*str, delim))
		{
			str++;
			continue ;
		}
		if (*str == '\0')
			return (NULL);
		break ;
	}
	char	*ret = str;
    while (1)
	{
		if (*str == '\0')
		{
            tmp = str;
            return (ret);
		}
        if (is_delim(*str, delim))
		{
			*str = '\0';
			tmp = str + 1;
			return (ret);
		}
		str++;
	}
}
