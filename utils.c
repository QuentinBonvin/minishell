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

void	split_with_pipe(char *line, t_shell *list)
{
	int		i;

	i = 0;
	if (list == NULL)
		printf("error malloc\n");
	list->token = my_strtok(line, TOK_DELIM);
	start_stack(&list->head, &list->tail, list->token);
	while (list->token != NULL)
	{
		list->token = my_strtok(NULL, TOK_DELIM);
		insert_beginning(&list->tail, list->token);
		i++;
	}
}

t_shell	*split_with_double_quote(char *line, t_shell *list)
{
	int		i;

	i = 0;
	if (list == NULL)
		printf("error malloc\n");
	list->token = my_strtok(line, "\"");
	if (list->head != NULL)
	{
		// free_cmd(list);
		// remove_node(list->head);
		// remove_node(list->tail);
	}
	start_stack(&list->head, &list->tail, list->token);
	while (list->token != NULL)
	{
		list->token = my_strtok(NULL, "\"");
		insert_beginning(&list->tail, list->token);
		// i++;
	}
	printf_cmd(list);
	list->token = NULL;
	return (list);
}

t_shell	*split_with_single_quote(char *line, t_shell *list)
{
	int		i;

	i = 0;
	if (list == NULL)
		printf("error malloc\n");
	list->token = my_strtok(line, "\'");
	if (list->head != NULL)
	{
		// free_cmd(list);
		// remove_node(list->head);
		// remove_node(list->tail);
	}
	start_stack(&list->head, &list->tail, list->token);
	while (list->token != NULL)
	{
		list->token = my_strtok(NULL, "\'");
		insert_beginning(&list->tail, list->token);
		// i++;
	}
	printf_cmd(list);
	list->token = NULL;
	return (list);
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
	free(current);
	// free(list->cmd);
}
