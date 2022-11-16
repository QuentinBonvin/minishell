#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	struct termios	saved;
	t_shell			*list;
	t_env			*env;

	if (void_argv_argc(argc, argv) == -1)
		return (EXIT_SUCCESS);
	list = malloc(sizeof(t_shell));
	env = malloc(sizeof(t_env));
	init_env(envp, env);
	init_list(list);
	while (1)
	{
		handle_signal(&saved);
		if (prompt(list, envp, &saved, env) == -1)
			break ;
	}
	return (EXIT_SUCCESS);
}

int	void_argv_argc(int argc, char **argv)
{
	(void)argv;
	if (argc > 1)
		return (-1);
	return (0);

}

int	prompt(t_shell *list, char **envp, struct termios *saved, t_env *env)
{
	char	*line;

	line = readline("\033[0;35mqbonvin_minishell ▸ \033[0;37m");
	if (!line)
	{
		printf("exit\n");
		//free_all(list, env, line);
		return (-1);
	}
	add_history(line);
	if (check_error(line) != -1)
	{
		list = check_line(line, list, env);
		init_pipe(list);
		is_redir(list);
		exec(list, envp, line, env);
		tcsetattr(STDIN_FILENO, TCSANOW, saved);
		free_cmd(list);
		free(line);
	}
	else
		free(line);
	return (0);
}
