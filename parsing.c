#include "minishell.h"

int	parsing_line(char *line)
{
	int			i;
	int			ret;

	i = 0;
	while (line[i])
	{
		if (line[i] == SIMPLE_QUOTE || line[i] == DOBBLE_QUOTE)
		{
			ret = check_quote(line, i, line[i]);
			if (ret == -1)
			{
				printf("error\n");
				return (-1);		
			}
			i = ret;
		}
		i++;
	}
	return (0);
}

void	split_with_pipe(char *line)
{
	int	i;
	// char *token;
	// char *test;
	t_shell *list;

	i = 0;
	list = malloc(sizeof(t_shell));
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
	printf_cmd(list);
}

void printf_cmd(t_shell *list)
{
    // t_node_cmd *actuel;
	t_cmd *current;

	current = list->head;
    if (list == NULL)
        exit(EXIT_FAILURE);
	while(current != NULL)
	{
		printf("%s\n", current->content);
		current = current->next;
	}
}
