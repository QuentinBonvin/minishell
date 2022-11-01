#include "minishell.h"

void	init_env(char **envp, t_shell *list)
{
	int		i;
	t_env	*env;

	i = 0;
	env = malloc(sizeof(t_env));
	while (envp[i])
	{
		if (i == 0)
			create_cell(&list->env_head, &list->env_tail, envp);
		else
		{
			add_envp_to_env(&list->env_tail, &envp[i]);
		}
		i++;
	}
	free(env);
}

void	*create_cell(t_env **env_head, t_env **env_tail, char **envp)
{
	t_env	*cell;

	(void)envp;
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

int	printf_env(t_shell *list)
{
	t_env	*curr;
	int		i;

	i = 0;
	curr = list->env_head;
	while (curr)
	{
		i = 0;
		while (curr->content[i] != '\0')
		{
			if (curr->content[i] == '=')
			{
				printf("%s\n", curr->content);
				break ;
			}
			i++;
		}
	curr = curr->prev;
	}
	return (0);
}

void	free_env(t_shell *list)
{
	t_env	*current;

	current = list->env_head;
	if (list == NULL)
		exit(EXIT_FAILURE);
	while (current->prev != NULL)
	{
		current = current->prev;
		free(current->next);
	}
	list->env_head = NULL;
	list->env_tail = NULL;
	free(current);
}
