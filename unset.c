#include "minishell.h"

int call_unset(t_shell *list, char *var)
{
	// (void)list;
	// printf("var: %s\n", var);
	if (var == NULL)
		return (0);
	ft_remove_from_list(list, var);
	return (0);
}


void	ft_remove_from_list(t_shell *list, char *var)
{
	t_env *curr;
	t_env *tmp;
	int		l;

	curr = list->env_head;
	l = ft_strlen(var);
	if (ft_delete_first_node(&list->env_head, curr, var))
		return ;
	while (curr != NULL && ft_strncmp(curr->content, var, l) != 0)
	{
		tmp = curr;
		curr = curr->prev;
	}
	if (var != NULL)
		return ;
	if (ft_strncmp(curr->content, var, l) == 0)
	{
		tmp->prev = curr->prev;
		// free(curr->content);
		free(curr);
	}
	else
		return ;
	// if (ft_strcmp(curr->content, var) == 0)

}

int	ft_delete_first_node(t_env **env_head, t_env *curr, char *var)
{
	if (!(ft_strcmp(curr->content, var)))
	{
		*env_head = curr->prev;
		free(curr);
		return (1);
	}
	return (0);
}