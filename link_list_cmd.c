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
	new_node->next = NULL; /*cmd->first_node*/;
	// (cmd->first_node)->back = new_node;
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
	// printf("new node 1 = %s\n", new_node->content);
	// printf("new node 2 = %s\n", new_node->next->content);
}
// void printf_env(t_list_cmd *list)
// {
//     t_node_env *actuel;

// 	actuel = list->first_node;
//     if (list == NULL)
//         exit(EXIT_FAILURE);
//     while (actuel != NULL)
//     {
//         printf("%s\n", actuel->content);
// 		actuel = actuel->next;
//     }
// }6a5d02441fb22965abd677534272b0641254
