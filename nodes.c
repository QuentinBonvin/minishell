#include "minishell.h"

void	*start_stack(t_cmd **head, t_cmd **tail, char *token)
{
	FILE* myFile = fopen("demo.txt", "w+");
	t_cmd	*new_node;

	new_node = malloc(sizeof(t_cmd));
	if (new_node == NULL)
		return (0);
	new_node->content = token;
	fprintf(myFile, "address of new_node->content\n%p\n", new_node->content);
	fprintf(myFile, "address of token\n%p\n", token);
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
	if (node->prev != NULL)
	{
		node->prev->next = node->next;
	}
	if (node->next != NULL)
	{
		node->next->prev = node->prev;
	}
	free(node);
	node = NULL;
}
