#include "minishell.h"

t_env	*sort_list(t_shell *list)
{
	t_env *p1;
	t_env *p2;
	t_env *copy;
	int		i;
	int		j;
	int		swapped;


	copy = ft_copy(list->env_head, list);
	i = (ft_count_env(list) + 1);
	j = 0;
	// curr = copy;
	while (j <= i)
	{
		copy = list->env_head;
		swapped = 0;
		while (0 < (i - j -1) || copy->content != NULL)
		{
			p1 = copy;
			p2 = p1->prev;
			// curr = copy;
			// while (copy != NULL)
			// {	
			if (p1->content[0] > p2->content[0])
			{
				copy = ft_swap(p1, p1->prev);
				swapped = 1;
			}
			p1 = p1->prev;
			p2 = p2->prev;
			copy = copy->prev;
			// }
			j++;
		}
		if (swapped == 0)
			break ;
		i++;
	}
	// print_list(copy);
	return (copy);
}


void	print_list(t_env *copy)
{
	t_env *tmp;

	tmp = copy;
	while (tmp != NULL)
	{
		tmp = tmp->prev;
	}
}
t_env	*ft_swap(t_env *p1, t_env *p2)
{
	char *tmp;

	tmp = NULL;
	// printf("p1: %s\n", p1->content);
	// printf("p1 next: %s\n", p2->content);
	// j = malloc(sizeof(char *) + 1);
	// if (p2->prev->content == NULL || p1->content == NULL) 
	// 	return (0);
	if (p1->prev == NULL)
		{
			tmp = p2->next->content;
			p2->next->content = p1->content;
			p1->content = tmp;
		}
	tmp = p2->content;
	p2->content = p1->content;
	p1->content = tmp;
	// printf("tmp after swap: %s\n", tmp);
	// printf("p1 after swap: %s\n", p1->content);
	// printf("p2 after swap: %s\n", p2->content);
	return (p2);
}



t_env	*ft_copy(t_env *curr, t_shell *list)
{
	t_env *curr2;
	t_env *new;
	t_env *tmp;

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
	// print_list(tmp);
	return (tmp);
}

int	ft_count_env(t_shell *list)
{
	int 	i;
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
	t_env *new;

	new = malloc(sizeof(t_env));
	if (new)
	{
		new->content = ft_strdup(node);
		new->prev = NULL;
	}
	return (new);
}
