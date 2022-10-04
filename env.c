#include "minishell.h"

void	init_env(char **envp)
{
	int		i;
	t_env	*env;

	i = 0;
	env = malloc(sizeof(t_env));
	while (envp[i])
	{
		i++;
		add_envp_to_env(env, envp, i);
	}
	printf_env(env);
}
