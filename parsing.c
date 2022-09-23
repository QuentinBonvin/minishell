/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:03:37 by qbonvin           #+#    #+#             */
/*   Updated: 2022/09/23 14:47:54 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parsing_line(char *line)
{
	int		i;
	// char	*test;

	i = 0;
	while (line[i])
	{
		if (ft_strchr(line, '|'))
		{
			split_with_pipe(line);
			break ;
		}
		i++;
	}
	// printf("%s\n", test);
}

void	split_with_pipe(char *line)
{
	int			i;
	// int			j;
	t_list_cmd	*list;
	char		*tmp;
	char		*pipe;
	
	i = 0;
	// j = 0;
	list = create_cmd();
	tmp = malloc(sizeof(char) * ft_strlen(line + 1));
	pipe = malloc(sizeof(char));
	while (line[i] /*|| line[i] != '|'*/)
	{
		if (line[i] != '|')
			tmp[i] = line[i];
		// printf("%s\n", tmp);
		if (line[i] == '|')
		{
			add_cmd_to_list(list, tmp);
			pipe[i] = line[i];
			add_cmd_to_list(list, &pipe[i]);
			tmp = ft_substr(line, ft_strlen(&line[i + 1]), ft_strlen(line));
			// tmp[i] = line[i];
			add_cmd_to_list(list, tmp);
			break ;
		}
		i++;
	}
		// i = 0;
		printf_cmd(list);
		// return (tmp);
}

void printf_cmd(t_list_cmd *list)
{
    // t_node_cmd *actuel;
	t_node_cmd *current;

	current = list->first_node;
    if (list == NULL)
        exit(EXIT_FAILURE);

	while(current != NULL)
	{
		printf("%s\n", current->content);
		current = current->next;
	}
	// current->next = current;
    // while (actuel->next != NULL)
    // {
    //     printf("%s\n", actuel->content);
	// 	actuel = actuel->next;
    // }
	// actuel->next = current;
}
