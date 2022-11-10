#include "minishell.h"

int	sort_list(t_env *env, char **arg)
{
	int		i;
	int		j;
	char	*tmp;
	char	*envp;

	i = 1;
	envp = NULL;
	if (arg[i] == NULL)
		print_array(env);
	else
	{
		while (arg[i])
		{
			j = -1;
			while (arg[i][++j])
			{
				if (arg[i][j] == '=')
				{
					tmp = ft_substr(arg[i], 0, j);
					envp = check_if_in_env(env, tmp);
					replace_in_env(env, envp, arg[i]);
					free(tmp);
					break ;
				}
			}
			if (envp == NULL)
				add_export_to_env(&env->env_tail, arg[i]);
			i++;
		}
	}
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

int	check_arg(char *arg)
{
	int	i;

	i = 0;
	if (ft_isdigit(arg[i]) == 1)
		return (-1);
	while (arg[i] && arg[i] != '=')
	{
		if (ft_isalpha(arg[i]) == 0)
			return (2);
		i++;
	}
	if (arg[i] != '=')
		return (3);
	return (1);
}

void	sort_and_swap(char **env_array, int l)
{
	int		swapped;
	char	*tmp;
	int		i;

	swapped = 0;
	while (env_array && swapped == 0)
	{
		swapped = 1;
		i = -1;
		while (++i < (l - 1))
		{
			if (ft_compare(env_array[i], env_array[i + 1]) > 0)
			{
				tmp = env_array[i];
				env_array[i] = env_array[i + 1];
				env_array[i + 1] = tmp;
				swapped = 0;
			}
		}
		l--;
	}
}

char	**convert_list(t_env *env)
{
	char	**env_array;
	int		length;
	t_env	*curr;
	int		i;

	i = 0;
	length = ft_count_env(env);
	curr = env->env_head;
	env_array = (char **)malloc(sizeof(char **) * (length + 2));
	while (curr)
	{
		env_array[i] = curr->content;
		curr = curr->prev;
		i++;
	}
	return (env_array);
}
