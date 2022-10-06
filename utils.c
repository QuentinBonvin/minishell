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
	// t_shell	*list;
	// char *token;
	// char *test;
	i = 0;
	// list = malloc(sizeof(t_shell));
	if (list == NULL)
		printf("error malloc\n");
	list->token = my_strtok(line, TOK_DELIM);
	start_stack(&list->head, &list->tail, list->token);
	// add_cmd_to_list(list, list->token);
	// test = ft_strrchr(line, ' ');
	while (list->token != NULL)
	{
		list->token = my_strtok(NULL, TOK_DELIM);
		// printf("token 2 = %s\n", token);
		insert_beginning(&list->head, list->token);
		// add_cmd_to_list(list, list->cmd->tokenn);
		// printf("after add_cmd 2 = %s\n", list->next->content);
		// printf("token = %s\n", list->token);
		i++;
	}
	// printf_cmd(list);
}

void	split_with_double_quote(char *line, t_shell *list)
{
	int		i;
	// t_shell	*list;
	// char *token;
	// char *test;
	i = 0;
	// list = malloc(sizeof(t_shell));
	if (list == NULL)
		printf("error malloc\n");
	list->token = my_strtok(line, "\"");
	start_stack(&list->head, &list->tail, list->token);
	// add_cmd_to_list(list, list->token);
	// test = ft_strrchr(line, ' ');
	while (list->token != NULL)
	{
		list->token = my_strtok(NULL, "\"");
		// printf("token 2 = %s\n", token);
		insert_beginning(&list->head, list->token);
		// add_cmd_to_list(list, list->cmd->tokenn);
		// printf("after add_cmd 2 = %s\n", list->next->content);
		// printf("token = %s\n", list->token);
		i++;
	}
	// printf_cmd(list);
}

void	split_with_single_quote(char *line, t_shell *list)
{
	int		i;
	// t_shell	*list;
	// char *token;
	// char *test;
	i = 0;
	// list = malloc(sizeof(t_shell));
	if (list == NULL)
		printf("error malloc\n");
	list->token = my_strtok(line, "\'");
	start_stack(&list->head, &list->tail, list->token);
	// add_cmd_to_list(list, list->token);
	// test = ft_strrchr(line, ' ');
	while (list->token != NULL)
	{
		list->token = my_strtok(NULL, "\'");
		// printf("token 2 = %s\n", token);
		insert_beginning(&list->head, list->token);
		// add_cmd_to_list(list, list->cmd->tokenn);
		// printf("after add_cmd 2 = %s\n", list->next->content);
		// printf("token = %s\n", list->token);
		i++;
	}
	// printf_cmd(list);
}

void	printf_cmd(t_shell *list)
{
	t_cmd	*current;
	//t_node_cmd *actuel;
	current = list->head;
	if (list == NULL)
		exit(EXIT_FAILURE);
	while (current != NULL)
	{
		printf("%s\n", current->content);
		current = current->next;
	}
}
