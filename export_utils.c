/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:32:18 by qbonvin           #+#    #+#             */
/*   Updated: 2022/11/18 17:03:39 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_array(t_env *env)
{
	char	**env_array;
	int		l;
	int		i;
	char	*envp;

	i = 0;
	l = 0;
	envp = NULL;
	env_array = convert_list(env);
	l = (ft_count_env(env));
	sort_and_swap(env_array, (l));
	while (i < (l))
	{
		printf("%s", "declare -x ");
		printf("%s\n", env_array[i]);
		i++;
	}
	free(env_array);
}

t_env	*ft_copy(t_env *curr, t_env *env)
{
	t_env	*curr2;
	t_env	*new;
	t_env	*tmp;

	curr2 = env->env_tail;
	tmp = NULL;
	new = malloc(sizeof(t_env));
	while (curr != NULL)
	{
		new = create_node(curr->content);
		if (tmp == NULL)
			tmp = new;
		else
			add_envp_to_env(&tmp, new->content);
		curr = curr->prev;
	}
	return (tmp);
}

int	ft_count_env(t_env *env)
{
	int		i;
	t_env	*curr;

	i = 0;
	curr = env->env_head;
	while (curr != NULL)
	{
		curr = curr->prev;
		i++;
	}
	return (i);
}

int	ft_compare(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' && s2[i] != '\0') && s1[i] == s2[i])
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
	new_node->content = ft_strdup(arg);
	new_node->prev = (*env_tail)->prev;
	(*env_tail)->prev = new_node;
	new_node->next = (*env_tail);
	if (new_node->prev != NULL)
		new_node->prev->next = new_node;
	return (0);
}
