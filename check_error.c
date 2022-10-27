#include "minishell.h"

int	check_error(char *line)
{
	if (check_data_to_lst(line) == -1)
	{
		return (-1);
	}
	// if (pipe_at_start_or_end(line) == -1)
	// 	return (-1);
	// if (only_one_simple_or_dobble_quote(line) == -1)
	// 	return (-1);
	// if (is_dobble_pipe(line) == -1)
	// 	return (-1);
	// if (space_after_pipe(line) == -1)
	// 	return (-1);
	// if (quote_have_no_pair(line) == -1)
	// 	return (-1);
	// if (check_dobble_pipe_before_quote(line) == -1)
	// 	return (-1);
	// if (last_check_dobble_pipe(line) == -1)
	// 	return (-1);
	return (0);
}

int    check_data_to_lst(char *data)
{
    int    i;
    int    j;

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
			if ((is_double_pipe(data, i) == -1) || (check_space_beetween_pipe(data, i) == -1) || 
                pipe_at_start_or_end(data) == -1)
				return (-1);
		}
        if (data[i] == '\0')
            return (0);
        if (data[i] != '\'' && data[i] != '\"')
            i++;
    }
    return (0);
}

int	check_space_beetween_pipe(char *data, int i)
{
	int find_char;

	find_char = 0;
    i++;
	while (data[i] != PIPE)
	{
        if (data[i] == '\0')
            break ;
		if (ft_isalpha(data[i]) == 1 || ft_isdigit(data[i]) == 1)
            find_char++;
	    i++;
	}
	if (find_char == 0)
		return (-1);
	return (0);
}

int	is_double_pipe(char *data, int i)
{
	if(data[i + 1] == PIPE)
	{
		printf("il y a double_pipe\n");
		return (-1);
	}
	return (0);
}

int    is_quote(char *data, int i)
{
    int    j;

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

int    is_s_quote(char *data, int i)
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

int    is_d_quote(char *data, int i)
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

int    after_is_quote(char *data, int i)
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