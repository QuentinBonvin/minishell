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
	//init_env(envp, list);
	// printf("%s\n", env->env_head->content);
	while (1)
	{
		handle_signal(&saved);
		line = readline("\033[0;35mqbonvin_minishell ▸ \033[0;37m");
		if (!line)
		{
			printf("exit\n");
			free(line);
			free_env(env);
			free(list);
			free(env);
			break ;
		}
		if (line[0] != '\0')
		{
			if (check_error(line))
			{
				//printf("error after check error\n");
				free(line);
				//return (0);
			}
			else
				prompt(line, list, envp, &saved, env);
		}
	}
	//printf("test exit\n");
	//free_tab_cmd(list);
	//exit(1);
	return (EXIT_SUCCESS);
}

void	void_argv_argc(int argc, char **argv)
{
	(void)argc;
	(void)argv;
}

void	prompt(char *line, t_shell *list, char **envp, struct termios *saved, t_env *env)
{
	// init_env(envp, env);
	list = check_line(line, list, env);
	init_pipe(list);
	is_redir(list);
	// if (list->head->redir_status != TRUE)
	// {
		exec(list,envp,line, env);
	// }
	add_history(line);
	tcsetattr(STDIN_FILENO, TCSANOW, saved);
	// free_env(env);
	free_cmd(list);
	free(line);
}

