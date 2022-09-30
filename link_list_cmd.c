#include "minishell.h"

// t_list_cmd	*create_cmd()
// {
// 	t_list_cmd	*list;
// 	t_node_cmd	*node;

// 	list = malloc(sizeof(t_list_cmd));
// 	node = malloc(sizeof(t_node_cmd));
// 	if (list == NULL || node == NULL)
// 		exit (EXIT_FAILURE);
// 	node->content = NULL;
// 	node->next = NULL;
// 	list->first_node = node;
// 	return (list);
// }

// void	add_cmd_to_list(t_cmd *cmd, char *line)
// {
// 	t_cmd	*new_node;

// 	new_node = malloc(sizeof(t_cmd));
// 	if (line == NULL || new_node == NULL)
// 		exit (EXIT_FAILURE);
// 	new_node->content = line;
// 	new_node->next = cmd->first_node;
// 	// (cmd->first_node)->back = new_node;
// 	cmd->first_node = new_node;
// }

t_cmd	*add_cmd_to_list(t_cmd *list, char *token)
{
	t_cmd 	*prec;
	t_cmd 	*curr;
	t_cmd 	*cell;
	int		i;

	curr = list;
	i = 0;
	cell = create_cmd(token);
	if (list == NULL)
	{	
		printf("Test\n");
		return (cell);
	}
	while (curr != NULL)
	{
		curr->content = token;
		prec = curr;
		curr = curr->next;
		i++;
	}
	prec->next = cell;
	cell->next = curr;
	return (list);
}

t_cmd	*create_cmd(char *token)
{
	t_cmd	*cell;
	(void)token;
	cell = malloc(sizeof(t_cmd));
	if (!(cell))
		return (NULL);
	cell->content = NULL;
	cell->next = NULL;
	cell->prev = NULL;
	return (cell);
}