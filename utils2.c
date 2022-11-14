#include "minishell.h"

void	free_all(t_shell *list, t_env *env, char *line)
{
	free(line);
	free_env(env);
	free(list);
	free(env);
}

t_env	*create_node(char *node)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (new)
	{
		new->content = ft_strdup(node);
		new->prev = NULL;
	}
	return (new);
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

int	check_command_not_found(int i, char *str, t_cmd	*curr)
{
	(void)str;
	if (i == 0)
	{
		printf("minishell: %s: command not found \n", curr->tab[0]);
		g_exit_status = 127;
		// if (str != NULL)
		// 	free(str);
		return (1);
	}
	// if (str != NULL)
	// 	free(str);
	return (0);
}
