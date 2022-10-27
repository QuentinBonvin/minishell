#include "minishell.h"

void	builtin(t_shell *list)
{
	t_cmd	*current;
	int		l;
	int		i;

	i = 0;
	l = 0;
	current = list->head;
	if (current->tab[0] == NULL)
		return ;
	l = ft_strlen((current->tab[0]));
	if (ft_strcmp(current->tab[0], "pwd") == 0)
		call_pwd();
	if ((ft_strncmp2(current->tab[0], "cd", l) == 0))
		call_cd(list, current->tab[1]);
	else if ((ft_strncmp2(current->tab[0], "echo", l) == 0))
		mini_echo(list, current->tab[1]);
	else if ((ft_strncmp2(current->tab[0], "export", l) == 0))
		sort_list(list, current->tab[1]);
	else if (ft_strcmp(current->tab[0], "unset") == 0)
		call_unset(list, current->tab[1]);
	else if (ft_strncmp2(current->tab[0], "env", l) == 0)
		printf_env(list);
	else if (ft_strncmp2(current->tab[0], "exit", l) == 0)
	{
		mini_exit(list, current->tab[1]);
		printf("exit works\n");
	}
	else
		search_env(list);
}

void	call_pwd(void)
{
	char	*aux;

	aux = getcwd(NULL, 0);
	printf("%s\n", aux);
	free(aux);
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
		i++;
	if (*s1 == *s2)
		return (0);
	else
		return (-1);
}

int	ft_strncmp2(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (i <= n)
	{
		if (s1[i] == '\0' || s2[i] == '\0')
			return (0);
		if (s1[i] != s2[i])
			return (((unsigned char)s1[i] - (unsigned char)s2[i]));
		i++;
	}
	return (-1);
}
