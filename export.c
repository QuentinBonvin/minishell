#include "minishell.h"

void	sort_list(t_shell *list)
{
	char **env_array;
	int		i;
	int		l;
	int		swapped;
	char	*tmp;

	swapped = 0 ;
	env_array = convert_list(list);
	l = (ft_count_env(list) + 1);
	// i = 0;
	// while (i < l)
	// {
	// 	// while (j < (l - i -1))
	// 	// {
	// 		while (env_array[i] > env_array[i + 1])
	// 		{
	// 			printf("env %s\n",env_array[i]);
	// 			printf("env + 1 %s\n", env_array[i + 1]);
	// 			ft_swap(env_array[i], (env_array[i + 1]));
	// 			// printf("%c\n", env_array[i][j]);
	// 			// swapped = 1;
	// 			i++;
	// 		}
	// 	// 	j++;
	// 	// }
	// 	// if (swapped == 0)
	// 	// 	break ;
	// 	i++;
	// }
	while (env_array && swapped == 0)
	{
		swapped = 1;
		i = 0;
		printf("%d\n", l);
		while (i < (l))
		{
			if (printf("i: %c\n", env_array[i][0] ) > printf("i + 1: %c\n", env_array[i + 1][0]))
			{
				tmp = env_array[i];
				env_array[i] = env_array[i + 1];
				env_array[i + 1] = tmp;
				swapped = 0;
				printf("env: %s\n", env_array[i + 1]);
			}
			i++;
		}
		l--;
	}
	print_array(env_array, l);
}

char **convert_list(t_shell *list)
{
	char	**env_array;
	int		length;
	t_env	*curr;
	int		i;

	i = 0;
	length = ft_count_env(list);
	curr = list->env_head;
	env_array = (char **)malloc(sizeof(char **) * (length));
	while (curr)
	{
		env_array[i] = curr->content;
		curr = curr->prev;
		i++;
	}
	return (env_array);
}

void	print_array(char **env_array, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		printf("%s\n", env_array[i]);
		i++;
	}
}

void	ft_swap(char *s1, char *s2)
{
	char tmp;
	int i;


	// tmp = NULL;
	i = 0;
	// printf("s1: %s\n", s1);
	// printf("s2: %s\n", s2);
	while (i < (int)ft_strlen(s2))
	{
		tmp = s1[i];
		s1[i] = s2[i];
		s2[i] = tmp;
		i++;
	}
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
