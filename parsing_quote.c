#include "minishell.h"

int	is_quote(char *data, int i)
{
	int	j;

	j = 0;
	if (data[i] == '\'')
	{
		j = i;
		i++;
		i = is_s_quote(data, i);
		if (i == -1)
			return (j);
	}
	if (data[i] == '\"')
	{
		j = i;
		i++;
		i = is_d_quote(data, i);
		if (i == -1)
			return (j);
	}
	return (i);
}

int	is_s_quote(char *data, int i)
{
	while (data[i] != '\'')
	{
		if (data[i] == '\0')
		{
			return (-1);
		}
		i++;
	}
	return (i);
}

int	is_d_quote(char *data, int i)
{
	while (data[i] != '\"')
	{
		if (data[i] == '\0')
		{
			return (-1);
		}
		i++;
	}
	return (i);
}

int	after_is_quote(char *data, int i)
{
	if (data[i] == '\'')
	{
		i++;
		while (data[i] != '\'')
		{
			if (data[i] == '\0')
				return (-1);
			i++;
		}
		if (data[i] == '|')
			return (-1);
	}
	if (data[i] == '\"')
	{
		i++;
		while (data[i] != '\"')
		{
			if (data[i] == '\0')
				return (-1);
			i++;
		}
		if (data[i] == '|')
			return (-1);
	}
	return (0);
}
