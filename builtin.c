#include "minishell.h"

void	builtin(t_shell *list)
{
	t_cmd	*current;
	char	*aux;
	int		i;
	int		l;

	current = list->head;
	i = 0;
	l = ft_strlen((current->content) - 1);
	if (ft_strcmp(&current->content[i], "pwd") == 0)
	{
		aux = getcwd(NULL, 0);
		call_pwd(aux);
	}
	if ((ft_strncmp2(&current->content[0], "cd", l) == 0))
		call_cd(aux, &list->head->content[1]);
	else if ((ft_strncmp2(&current->content[0], "echo", l) == 0))
		mini_echo(list, list->head->content);
	else if ((ft_strncmp2(&current->content[0], "export", l) == 0))
		printf("export works\n");
	else if (ft_strcmp(&current->content[0], "unset") == 0)
		call_unset(list, list->head->prev->content);
	else if (ft_strncmp2(&current->content[0], "env", l) == 0)
		printf_env(list);
	else if (ft_strncmp2(&current->content[0], "exit", l) == 0)
		printf("exit works\n");
	else
		search_env(list);
}

void	call_pwd(char *aux)
{
	printf("%s\n", aux);
}

char	*search_env(t_shell *list)
{
	int		i;
	t_env	*curr;

	i = 0;
	curr = list->env_head;
	while (curr)
	{
		if (ft_strcmp(curr->content, "PATH") == 0)
		{
			// printf("%s\n", curr->content);
			return (curr->content);
		}
		curr = curr->prev;
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' && s2[i] != '\0') && s1[i] == s2[i])
	{
		i++;
		// printf("s1: %s\n", s1);
		// printf("s2: %s\n", s2);
	}
	if (*s1 == *s2)
	{
		return (0);
	}
	else
		return (-1);
}

int	ft_strncmp2(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	// printf("s1: %s\n", s1);
	// printf("s2: %s\n", s2);
	while (i < n)
	{
		if (s1[i] == '\0' || s2[i] == '\0')
		{
			// printf("s1: %c\n", s1[i]);
			// printf("s2: %c\n", s2[i]);
			return (0);
		}
		if (s1[i] != s2[i])
			return (((unsigned char)s1[i] - (unsigned char)s2[i]));
		i++;
	}
	return (-1);
}

// int	ft_strcmp3(char *s1, char *s2, int i)
// {
// 	while ((s1[i] != '\0' && s2[i] != '\0') && s1[i] == s2[i])
// 	{
// 		i++;
// 		printf("s1: %s\n", s1);
// 		printf("s2: %s\n", s2);
// 	}
// 	if (*s1 == *s2)
// 	{
// 		return (0);
// 	}
// 	else
// 		return (-1);
// }