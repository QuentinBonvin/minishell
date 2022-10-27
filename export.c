#include "minishell.h"

void	sort_list(t_shell *list, char *arg)
{
	char	**env_array;
	int		l;
	int		i;
	char	*tmp;
	char	*env;

	i = 0;
	env = NULL;
	env_array = convert_list(list);
	l = (ft_count_env(list));
	sort_and_swap(env_array, (l));
	if (arg == NULL)
	{
		print_array(env_array, (l + 1));
	}
	else
	{
		while (arg[i])
		{
			if (arg[i] == '=')
			{
				tmp = ft_substr(arg, 0, i);
				// printf("tmp: %s\n", tmp);
				env = check_if_in_env(list, tmp);
				break ;
			}
			else
				env = NULL;
			i++;
		}
	}
	if (env != NULL)
	{
		printf("env:%s\n", env);
		// printf("arg: %s\n", arg);
		replace_in_env(list, env, arg);
	}
	else
		add_export_to_env(&list->env_tail, arg);
}

void	replace_in_env(t_shell *list, char *env, char *arg)
{
	t_env	*curr;

	curr = list->env_head;
	while (curr)
	{
		if (curr->content == env)
			curr->content = arg;
		curr = curr->prev;
	}
}

char	*check_if_in_env(t_shell *list, char *arg)
{
	t_env	*curr;
	int		i;
	int		l;

	curr = list->env_head;
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

char	**convert_list(t_shell *list)
{
	char	**env_array;
	int		length;
	t_env	*curr;
	int		i;

	i = 0;
	length = ft_count_env(list);
	curr = list->env_head;
	env_array = (char **)malloc(sizeof(char **) * (length + 2));
	while (curr)
	{
		env_array[i] = curr->content;
		curr = curr->prev;
		i++;
	}
	return (env_array);
}
