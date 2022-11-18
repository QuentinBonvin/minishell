/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:26:19 by qbonvin           #+#    #+#             */
/*   Updated: 2022/11/18 14:26:22 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	string_search(char *line, char c)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == c)
			return (-1);
		i++;
	}
	return (0);
}

int	string_start(char *line, char c)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == c)
			return (i);
		i++;
	}
	return (0);
}

void	printf_cmd(t_shell *list)
{
	t_cmd	*current;

	current = list->head;
	if (list == NULL)
		exit(EXIT_FAILURE);
	while (current != NULL)
	{
		printf("commande = %s\n", current->content);
		current = current->prev;
	}
}

void	free_cmd(t_shell *list)
{
	t_cmd	*current;
	int		i;

	i = 0;
	current = list->head;
	if (list == NULL)
		exit(EXIT_FAILURE);
	while (current->next != NULL)
	{
		current = current->prev;
		free(current->prev->content);
	}
	list->head = NULL;
	list->tail = NULL;
	while (current->tab[i])
	{
		free(current->tab[i]);
		i++;
	}
	free(current->tab);
	free(current);
}

void	init_list(t_shell *list)
{
	list->head = NULL;
	list->tail = NULL;
	list->cmd = NULL;
	list->end = 0;
	list->start = 0;
	list->token = NULL;
}
