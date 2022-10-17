#include "minishell.h"

void	*start_stack(t_cmd **head, t_cmd **tail, char *token)
{
	t_cmd	*new_node;

	new_node = malloc(sizeof(t_cmd));
	if (new_node == NULL)
		return (0);
	new_node->content = token;
	new_node->next = NULL;
	new_node->prev = NULL;
	*head = new_node;
	*tail = new_node;
	return (0);
}

void	*insert_beginning(t_cmd **tail, char *token)
{
	t_cmd	*new_node;

	new_node = malloc(sizeof(t_cmd));
	if (new_node == NULL)
		return (0);
	new_node->content = token;
	new_node->next = *tail;
	new_node->prev = NULL;
	(*tail)->prev = new_node;
	*tail = new_node;
	return (0);
}

void	remove_node(t_cmd *node)
{
	if (node->next != NULL)
	{
		node->next->prev = node->prev;
	}
	if (node->prev != NULL)
	{
		node->prev->next = node->next;
	}
	free(node);
	node = NULL;
}