#include "minishell.h"

int call_unset(t_shell *list, char *var)
{
	// (void)list;
	// printf("%s\n", line);
	ft_remove_from_list(list, var);
	return (0);
}


void	ft_remove_from_list(t_shell *list, char *var)
{
	t_env *curr;

	curr = list->env_head;
	printf("%s\n", var);
	while (curr != NULL && ft_strcmp(curr->content, var) != 0)
	{
		curr = curr->prev;
	}
	if (ft_strcmp(curr->content, var) == 0)
		printf("%s\n", curr->content);

}