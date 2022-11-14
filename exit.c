#include "minishell.h"

int	mini_exit(t_shell *list, char *arg, char *line, t_env *env)
{
	(void)env;
	(void)list;
	if (arg == NULL)
	{
		free_env(env);
		free(line);
		exit (g_exit_status);
	}
	else
	{
		g_exit_status = ft_atoi((arg));
	}
	return (g_exit_status);
}

int	call_pwd(void)
{
	char	*aux;

	aux = getcwd(NULL, 0);
	printf("%s\n", aux);
	free(aux);
	return (0);
}
