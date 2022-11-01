#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	struct termios	saved;
	char			*line;
	t_shell			*list;

	(void)argc;
	(void)argv;
	list = malloc(sizeof(t_shell));
	init_list(list);
	init_env(envp, list);
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
				//printf("error after check error\n");
				free(line);
				//return (0);
			}
			else
			{
				list = check_line(line, list);
				init_pipe(list);
				exec(list,envp,line);
				add_history(line);
				tcsetattr(STDIN_FILENO, TCSANOW, &saved);
				free_cmd(list);
				free(line);
			}
		}
	}
	free(line);
	free_env(list);
	free(list);
	exit(1);
	return (EXIT_SUCCESS);
}
