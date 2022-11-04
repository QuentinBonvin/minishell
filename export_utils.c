#include "minishell.h"

void	print_array(char **env_array, int len)
{
	int	i;

	i = 0;
	while (i < (len - 1))
	{
		printf("%s", "declare -x ");
		printf("%s\n", env_array[i]);
		i++;
	}
}

t_env	*ft_copy(t_env *curr, t_shell *list)
{
	t_env	*curr2;
	t_env	*new;
	t_env	*tmp;

	curr2 = list->env_tail;
	tmp = NULL;
	new = malloc(sizeof(t_env));
	while (curr != NULL)
	{
		new = create_node(curr->content);
		if (tmp == NULL)
			tmp = new;
		else
			add_envp_to_env(&tmp, &new->content);
		curr = curr->prev;
	}
	return (tmp);
}

int	ft_count_env(t_shell *list)
{
	int		i;
	t_env	*curr;

	i = 0;
	curr = list->env_head;
	while (curr != NULL)
	{
		curr = curr->prev;
		i++;
	}
	return (i);
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

int	ft_compare(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	// printf("s1: %s\n", s1);
	// printf("s2: %s\n", s2);
	while((s1[i] != '\0' && s2[i] != '\0') && s1[i] == s2[i])
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	*add_export_to_env(t_env **env_tail, char *arg)
{
	t_env	*new_node;

	new_node = malloc(sizeof(t_env));
	if (new_node == NULL)
		return (0);
	new_node->content = arg;
	new_node->prev = (*env_tail)->prev;
	(*env_tail)->prev = new_node;
	new_node->next = (*env_tail);
	if (new_node->prev != NULL)
		new_node->prev->next = new_node;
	return (0);
}
