/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:46:27 by qbonvin           #+#    #+#             */
/*   Updated: 2022/11/18 15:26:19 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_error(char *line)
{
	if (only_space(line) == -1)
		return (-1);
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
	if (data[i] == '\0')
		return (-1);
	while (data[i])
	{
		j = i;
		i = is_quote(data, i);
		if (j != i)
			i++;
		if (check_another_quote(data, i) == -1)
			return (-1);
		if (data[i] == '|')
			if (check_pipe(data, i) == -1)
				return (-1);
		if (data[i] == '\0')
			return (0);
		if (data[i] != '\'' && data[i] != '\"')
			i++;
	}
	return (0);
}

int	check_pipe(char *data, int i)
{
	if (is_double_pipe(data, i) || (pipe_at_start_or_end(data) == -1
			|| check_space_beetween_pipe(data, i) == -1))
		return (-1);
	return (0);
}

int	check_another_quote(char *data, int i)
{
	if (after_is_quote(data, i) == -1)
	{
		printf("error parsing quote\n");
		return (-1);
	}
	return (0);
}

int	only_space(char *line)
{
	int	i;
	int	space;

	i = 0;
	space = 0;
	while (line[i])
	{
		if (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
			space++;
		i++;
	}
	if (space == i)
		return (-1);
	return (0);
}
