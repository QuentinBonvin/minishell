#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	struct termios	saved;
	char			*line;
	t_shell			*list;
	t_env			*env;

	void_argv_argc(argc, argv);
	list = malloc(sizeof(t_shell));
	env = malloc(sizeof(t_env));
	init_env(envp, env);
	init_list(list);
	while (1)
	{
		handle_signal(&saved);
		line = readline("\033[0;35mqbonvin_minishell ▸ \033[0;37m");
		if (!line)
		{
			printf("exit\n");
			free_all(list, env, line);
			break ;
		}
		else
		{
			if (check_error(line))
				free(line);
			else
				prompt(line, list, envp, &saved, env);
		}
	}
	return (EXIT_SUCCESS);
}

void	void_argv_argc(int argc, char **argv)
{
	(void)argc;
	(void)argv;
}

void	prompt(char *line, t_shell *list, char **envp, struct termios *saved, t_env *env)
{
	(void)saved;
	list = check_line(line, list, env);
	init_pipe(list);
	is_redir(list);
	exec(list, envp, line, env);
	add_history(line);
	// tcsetattr(STDIN_FILENO, TCSANOW, saved);
	free_cmd(list);
	free(line);
}
