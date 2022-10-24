#include "minishell.h"

t_shell	*check_line(char *line, t_shell *list)
{
	list->double_quote = 0;
	list->single_quote = 0;
	ft_split2(line, '|', list);
	// list_to_array(list);
	printf_cmd(list);
	return (list);
}

// int	parsing_line(char *line, t_shell *list)
// {
// 	int			i;
// 	int			ret;

// 	i = 0;
// 	ret = 0;
// 	if ((string_search(line, '\'') == -1))
// 	{
// 		list->start = string_start(line, '\'' );
// 		list->end = check_quote(line, list->start, line[list->start]);
// 			list->end += 1;
// 		while (line[list->end])
// 		{
// 			if (line[list->end] == '|')
// 				split_with_pipe1(line, list);
// 			list->end++;
// 		}
// 	}
// 	else if (((string_search(line, '\"') == -1)))
// 	{
// 		list->start = string_start(line, '\"' );
// 		list->end = check_quote(line, list->start, line[list->start]);
// 		list->end += 1;
// 		while (line[list->end])
// 		{
// 			if (line[list->end] == '|')
// 				split_with_pipe1(line, list);
// 			list->end++;
// 		}
// 	}
// 	else if (string_search(line, '\'') == 0  && string_search(line, '\"') == 0 )/*&& string_search(line, '|') != 0)*/
// 	{
// 		split_with_pipe(line, list);
// 		// return (-1);
// 	}
	// list_to_array(list);
	// while (line[i])
	// {
	// 	if (line[i] == SIMPLE_QUOTE)
	// 	{
	// 		ret = check_quote(line, i, line[i]);
	// 		i = ret;
	// 	list->single_quote = 1;
	// 	}
	// 	if (line[i] == DOBBLE_QUOTE)
	// 	{
	// 		ret = check_quote(line, i, line[i]);
	// 		i = ret;
	// 		list->double_quote = 1;
	// 	}
	// 	i++;
	// }
// 	printf_cmd(list);
// 	return (0);
// }

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
