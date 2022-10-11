#include "minishell.h"

// int	parsing_line(char *line, t_shell *list)
// {
// 	int			i;
// 	int			ret;

// 	i = 0;
// 	if (!string_search(line, '\'') || string_search(line, '\"'))
// 	{
// 		split_with_pipe(line, list);
// 		return (-1);
// 	}
// 	while (line[i])
// 	{
// 		if (line[i] == SIMPLE_QUOTE)
// 		{
// 			ret = check_quote(line, i, line[i]);
// 			if (ret == -1)
// 			{
// 				printf("error\n");
// 				return (-1);
// 			}
// 			i = ret;
// 		list->single_quote = 1;
// 		}
// 		if (line[i] == DOBBLE_QUOTE)
// 		{
// 			ret = check_quote(line, i, line[i]);
// 			if (ret == -1)
// 			{
// 				printf("error\n");
// 				return (-1);
// 			}
// 			i = ret;
// 			list->double_quote = 1;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

t_shell	*check_line(char *line, t_shell *list)
{
	int res;

	if (check_error(line))
	{
		printf("error\n");
		//return (0);
	}
	res = parsing_line(line, list);
	if (res == 0 && list->double_quote == 1)
	{
		list = split_with_double_quote(line, list);
	}
	if (res == 0 && list->single_quote == 1)
	// if (parsing_line(line, list) == 0 && list->double_quote == 1)
	// 	split_with_double_quote(line, list);
	// if (parsing_line(line, list) == 0 && list->single_quote == 1)
		split_with_single_quote(line, list);
	// printf("list manual: %s\n", list->head->prev->content);
	// printf_cmd(list);
	return (list);
}

int	check_error(char *line)
{
	if (pipe_at_start_or_end(line) == -1)
		return (-1);
	if (only_one_simple_or_dobble_quote(line) == -1)
		return (-1);
	if (is_dobble_pipe(line) == -1)
		return (-1);
	if (space_after_pipe(line) == -1)
		return (-1);
	if (quote_have_no_pair(line) == -1)
		return (-1);
	if (check_dobble_pipe_before_quote(line) == -1)
		return (-1);
	if (last_check_dobble_pipe(line) == -1)
		return (-1);
	return (0);
}

int	check_dobble_pipe_before_quote(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != DOBBLE_QUOTE && line[i] != SIMPLE_QUOTE)
	{
		if (line[i] == PIPE)
			if (line[i + 1] == PIPE)
			{
				printf("pipe before quote\n");
				return (-1);
			}
		i++;
	}
	return (0);
}


int last_check_dobble_pipe(char *line)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	j = 0;
	ret = 0;
	while (line[i])
	{
		if (line[i] == DOBBLE_QUOTE || line[i] == SIMPLE_QUOTE || line[i] == PIPE)
		{
			ret = pipe_in_quote(&line[i + 1]);
			if (ret == 0 && line[i] != PIPE)
				i++;
			if (line[i] == PIPE && ret != 0)
			{
				j = i;
				while (line[j])
				{
					if (line[j] == PIPE)
					{	
						if (line[j + 1] == PIPE)
						{
							printf("il y a 2 pipe\n");
							return (-1);
						}
						else
							break ;
					}
					j++;
				}
			}
		}
		i++;
	}
	return (0);
}


int	parsing_line(char *line, t_shell *list)
{
	int			i;
	int			ret;

	i = 0;
	if (!string_search(line, '\'') || string_search(line, '\"'))
	{
		split_with_pipe(line, list);
		return (-1);
	}
	while (line[i])
	{
		if (line[i] == SIMPLE_QUOTE)
		{
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

// void	check_line(char *line, t_shell *list)
// {
// 	if (parsing_line(line, list) == 0 && list->double_quote == 1)
// 		split_with_double_quote(line, list);
// 	if (parsing_line(line, list) == 0 && list->single_quote == 1)
// 		split_with_single_quote(line, list);
// }

int	nbr_pipe_in_string(char *line)
{
	int	i;
	int	nbr_pipe;

	nbr_pipe = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '|')
			nbr_pipe++;
		i++;
	}
	return (nbr_pipe);
}
