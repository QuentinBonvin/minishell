#include "minishell.h"

int	mini_exit(t_cmd *curr, char *arg, char *line, t_env *env)
{
	int i;

	i = 0;
	(void)curr;
	if (arg != NULL)
	{
		i = ft_atoi(arg);
		printf("exit\n");
		free_env(env); 
		free(line);
		exit (i);
	}
	else
	{
		printf("exit\n");
		free_env(env); 
		free(line);
		exit (g_exit_status);
	}
	return (0);
}

int	call_pwd(void)
{
	char	*aux;

	aux = getcwd(NULL, 0);
	printf("%s\n", aux);
	free(aux);
	return (0);
}
