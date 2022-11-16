#include "minishell.h"

void	init_env(char **envp, t_env *env)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (i == 0)
			create_cell(&env->env_head, &env->env_tail, &envp[i]);
		else
		{
			add_envp_to_env(&env->env_tail, &envp[i]);
		}
		i++;
	}
}

void	*create_cell(t_env **env_head, t_env **env_tail, char **envp)
{
	t_env	*cell;

	cell = malloc(sizeof(t_env));
	if (!(cell))
		return (NULL);
	cell->content = *envp;
	cell->next = NULL;
	cell->prev = NULL;
	*env_head = cell;
	*env_tail = cell;
	return (0);
}

void	*add_envp_to_env(t_env **env_tail, char **envp)
{
	t_env	*new_node;

	new_node = malloc(sizeof(t_env));
	if (new_node == NULL)
		return (0);
	new_node->content = *envp;
	new_node->next = *env_tail;
	new_node->prev = NULL;
	(*env_tail)->prev = new_node;
	*env_tail = new_node;
	return (0);
}

int	printf_env(t_env *env, t_cmd *current)
{
	int		i;
	t_env	*curr;

	curr = env->env_head;
	if (current->tab[1] != NULL)
	{
		printf("env: %s: No such file or directory\n", current->tab[1]);
		g_exit_status = 127;
		return (127);
	}
	while (curr)
	{
		i = -1;
		while (curr->content[++i] != '\0')
		{
			if (curr->content[i] == '=')
			{
				printf("%s\n", curr->content);
				break ;
			}
		}
	curr = curr->prev;
	}
	return (0);
}

void	free_env(t_env *env)
{
	t_env	*current;

	current = env->env_head;
	if (env == NULL)
		exit(EXIT_FAILURE);
	while (current->prev != NULL)
	{
		current = current->prev;
		free(current->next);
	}
	env->env_head = NULL;
	env->env_tail = NULL;
	free(current);
}
