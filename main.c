#include "minishell.h"


int	main(int argc, char **argv, char **envp)
{
	struct termios	saved;
	
	char		*line;
	t_shell		*list;
	(void)argc;
	(void)argv;

	list = malloc(sizeof(t_shell));
	init_env(envp,list);
	while (1)
	{
		handle_signal(&saved);
		line = readline("\033[0;35mqbonvin_minishell ▸ \033[0;37m");
		if (!line)
			break ;
		if (line[0] != '\0')
		{
			if (check_error(line))
			{
				printf("error after check error\n");
				// free(line);
				// free(list);
				return (0);
			}
			list = check_line(line, list);
			// builtin(line, list);
			// check_line(line, list);
			// check_line(line, list);
			builtin(list);
			add_history(line);
			tcsetattr(STDIN_FILENO, TCSANOW, &saved);
			// free(line);
			// free(list);
		}
	}
	return (EXIT_SUCCESS);
}

void	*create_cell(t_env **env_head, t_env **env_tail, char **envp)
{
	t_env	*cell;

	(void)envp;
	cell = malloc(sizeof(t_env));
	if (!(cell))
		return (NULL);
	cell->content = *envp;
	cell->next = NULL;
	cell->prev = NULL;
	*env_head = cell;
	*env_tail = cell;
	return (0);
}

void	*add_envp_to_env(t_env **env_tail, char **envp)
{
	t_env	*new_node;

	new_node = malloc(sizeof(t_env));
	if (new_node == NULL)
		return 0;
	new_node->content = *envp;
	new_node->next = *env_tail;
	new_node->prev = NULL;
	(*env_tail)->prev = new_node;
	*env_tail = new_node;
	return (0);
}
