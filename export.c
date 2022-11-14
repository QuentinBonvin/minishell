#include "minishell.h"

int	sort_list(t_env *env, char **arg)
{
	int		i;
	int		j;
	char	*envp;
	int		ret;

	i = 1;
	ret = 0;
	envp = NULL;
	if (arg[i] == NULL)
		print_array(env);
	else
	{
		while (arg[i])
		{
			j = 0;
			printf("%s\n", arg[i]);
			while (arg[i][j])
			{
				ret = ft_equal(arg, i, j, env);
				if (ret == 0)
					break ;
				j++;
			}
			if (ret == 0)
				add_export_to_env(&env->env_tail, arg[i]);
			i++;
		}
	}
	return (0);
}

int	ft_equal(char **arg, int i, int j, t_env *env)
{
	char	*tmp;
	char	*envp;

	tmp = ft_substr(arg[i], 0, j);
	envp = check_if_in_env(env, arg[i]);
	if (arg[i][j] == '=')
	{
		replace_in_env(env, envp, arg[i]);
		return (1);
	}
	free(tmp);
	return (0);
}

void	replace_in_env(t_env *env, char *envp, char *arg)
{
	t_env	*curr;

	curr = env->env_head;
	while (curr)
	{
		if (curr->content == envp)
		{
			curr->content = ft_strdup(arg);
		}
		curr = curr->prev;
	}
}

char	*check_if_in_env(t_env *env, char *arg)
{
	t_env	*curr;
	int		i;
	int		l;

	curr = env->env_head;
	l = ft_strlen(arg);
	i = 0;
	while (curr)
	{
		if (ft_strncmp(curr->content, arg, l) == 0)
			return (curr->content);
		curr = curr->prev;
	}
	return (NULL);
}
