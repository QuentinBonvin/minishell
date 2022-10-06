#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char		*line;
	t_shell		*list;

	(void)argc;
	(void)argv;
	list = malloc(sizeof(t_shell));
	// signal(SIGINT, sig_handler);
	// signal(SIGQUIT, sig_quit);
	init_env(envp,list);
	while (1)
	{
		line = readline("\033[0;35mqbonvin_minishell ▸ \033[0;37m");
		check_line(line, list);
		builtin(line, list);
		add_history(line);
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
	// printf("%s\n", cell->content);
	return (0);
}

void	*add_envp_to_env(t_env **env_head, char **envp)
{
	t_env	*new_node;

	new_node = malloc(sizeof(t_env));
	if (new_node == NULL)
		return 0;
	new_node->content = *envp;
	new_node->next = *env_head;
	new_node->prev = NULL;
	(*env_head)->prev = new_node;
	*env_head = new_node;
	return (0);
}
