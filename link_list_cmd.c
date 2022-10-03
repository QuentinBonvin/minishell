#include "minishell.h"

t_cmd	*add_cmd_to_list(t_cmd *list, char *token)
{
	t_cmd	*prec;
	t_cmd	*curr;
	t_cmd	*cell;
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
