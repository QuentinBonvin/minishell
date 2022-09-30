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
	char *token;
	char *test;
	t_cmd *list;

	i = 0;
	list = malloc(sizeof(t_cmd));
	if (list == NULL)
		printf("error malloc\n");
	token = my_strtok(line, "|");
	// printf("token 1 = %s\n", token);
	//add_cmd_to_list(list, token);
	// printf("after add_cmd = %s\n", list->content);
	test = ft_strrchr(line, ' ');
	printf("test = %s\n", test);
	while (line[i])
	{
		token = my_strtok(NULL, "|");
		// printf("token 2 = %s\n", token);
		// add_cmd_to_list(list, token);
		// printf("after add_cmd 2 = %s\n", list->next->content);
		i++;
		printf_cmd(list);
	}
}

void printf_cmd(t_cmd *list)
{
    // t_node_cmd *actuel;
	t_cmd *current;

	current = list;
    if (list == NULL)
        exit(EXIT_FAILURE);
	while(current != NULL)
	{
		printf("%s\n", current->content);
		current = current->next;
	}
}
