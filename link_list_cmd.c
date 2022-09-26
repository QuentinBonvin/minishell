/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_list_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:51:27 by qbonvin           #+#    #+#             */
/*   Updated: 2022/09/23 12:23:14 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list_cmd	*create_cmd()
{
	t_list_cmd	*list;
	t_node_cmd	*node;

	list = malloc(sizeof(t_list_cmd));
	node = malloc(sizeof(t_node_cmd));
	if (list == NULL || node == NULL)
		exit (EXIT_FAILURE);
	node->content = NULL;
	node->next = NULL;
	list->first_node = node;
	return (list);
}

void	add_cmd_to_list(t_list_cmd *cmd, char *line)
{
	t_node_cmd	*new_node;

	new_node = malloc(sizeof(t_node_cmd));
	if (line == NULL || new_node == NULL)
		exit (EXIT_FAILURE);
	new_node->content = line;
	new_node->next = cmd->first_node;
	cmd->first_node = new_node;
}

void printf_cmd(t_list_cmd *list)
{
    t_node_cmd *actuel;

	actuel = list->first_node;
    if (list == NULL)
        exit(EXIT_FAILURE);
    while (actuel != NULL)
    {
        printf("%s\n", actuel->content);
		actuel = actuel->next;
    }
}