/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:03:37 by qbonvin           #+#    #+#             */
/*   Updated: 2022/09/23 12:29:01 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parsing_line(char *line)
{
	int			i;

	i = 0;
	while (line[i])
	{
		if (ft_strchr(line, '|'))
			split_with_pipe(line);
		i++;
	}
	//printf("%s\n", test);
}

char	*split_with_pipe(char *line)
{
	int			i;
	t_list_cmd	*list;
	char		*tmp;
	
	i = 0;
	list = create_cmd();
	tmp = malloc(sizeof(char) * ft_strlen(line));
	while (line[i] || line[i] != '|')
	{
		if (line[i] != '|')
			tmp[i] = line[i];
		if (line[i] == '|')
			add_cmd_to_list(list, tmp);
		i++;
		printf_cmd(list);
	}
	return (0);
}