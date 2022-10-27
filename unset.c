#include "minishell.h"

int	call_unset(t_shell *list, char *var)
{
	if (var == NULL)
		return (0);
	ft_remove_from_list(list, var);
	return (0);
}

void	ft_remove_from_list(t_shell *list, char *var)
{
	t_env	*curr;
	t_env	*tmp;
	int		l;

	curr = list->env_head;
	l = (ft_strlen(var) + 1);
	if (ft_delete_first_node(&list->env_head, curr, var))
		return ;
	while (curr != NULL && ft_strncmp2(curr->content, var, l) != 0)
	{
		tmp = curr;
		curr = curr->prev;
	}
	if (ft_strncmp2(curr->content, var, l) == 0)
	{
		tmp->prev = curr->prev;
		// free(curr->prev);
		free(curr);
	}
	else
		return ;
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
