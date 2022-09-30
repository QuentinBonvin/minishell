#include "minishell.h"

void	parsing_line(char *line)
{
	int			i;
	char		*token;
	char		*test;
	t_list_cmd	*list;

	list = create_cmd();
	i = 0;
<<<<<<< HEAD
<<<<<<< HEAD
=======
	token = my_strtok(line, "|");
>>>>>>> 47e5b4720e78431a8f0e744048bddcd76402a55d
	while (line[i])
	{
		if (line[i] == SIMPLE_QUOTE || line[i] == DOBBLE_QUOTE)
		{
			test = check_quote(&line[i + 1]);

			add_cmd_to_list(list, token);
			token = my_strtok(NULL, "|");
		}
		i++;
	}
}

void	split_with_pipe(char *line)
{
	t_list_cmd	*list;
	int			i;
	char		*tmp;
	char		*pipe;

	i = 0;

	list = create_cmd();
	tmp = malloc(sizeof(char) * ft_strlen(line));
	while (line[i] || line[i] != '|')
	{
		pipe = malloc(sizeof(char));
		while (line[i] /*|| line[i] != '|'*/)
		{
			if (line[i] != '|')
				tmp[i] = line[i];
			// printf("%s\n", tmp);
			if (line[i] == '|')
				add_cmd_to_list(list, tmp);
			{
				add_cmd_to_list(list, tmp);
				pipe[i] = line[i];
				add_cmd_to_list(list, &pipe[i]);
				tmp = ft_substr(line, ft_strlen(&line[i + 1]), ft_strlen(line));
				// tmp[i] = line[i];
				add_cmd_to_list(list, tmp);
				break ;
			}
			i++;
			printf_cmd(list);
		}
			// i = 0;
			printf_cmd(list);
			// return (tmp);
	}
<<<<<<< HEAD
=======
		// i = 0;
		// printf_cmd(list);
		// return (tmp);
>>>>>>> Nik
}

void printf_cmd(t_list_cmd *list)
{
    // t_node_cmd *actuel;
	t_node_cmd *current;

	current = list->first_node;
    if (list == NULL)
        exit(EXIT_FAILURE);
	while(current != NULL)
	{
		printf("%s\n", current->content);
		current = current->next;
	}
}
