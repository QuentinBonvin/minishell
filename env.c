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
			add_envp_to_env(&list->env_head, &envp[i]);
			// printf("%s\n", list->env_head->content);
		}
		i++;
	}
	printf_env(list);
}

void	printf_env(t_shell *list)
{
	t_env *curr;

	curr = list->env_head;
	while (curr != NULL)
	{
		printf("%s\n", curr->content);
		curr = curr->next;
	}
}