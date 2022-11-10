#include "minishell.h"

int	builtin(t_shell *list, char **envp, char *line)
{
	t_cmd	*current;
	int		i;

	i = 0;
	(void)envp;
	(void)line;
	current = list->head;
	if (current->tab[0] == NULL)
		return (-1);
	if (ft_strncmp2(current->tab[0], "pwd", 4) == 0)
		return (0);
	else if ((ft_strncmp2(current->tab[0], "cd", 3) == 0))
		return (0);
	else if ((ft_strncmp2(current->tab[0], "echo", 4) == 0))
		return (0);
	else if ((ft_strncmp2(current->tab[0], "export", 6) == 0))
		return (0);
	else if (ft_strcmp(current->tab[0], "unset") == 0)
		return (0);
	else if (ft_strncmp2(current->tab[0], "env", 4) == 0)
		return (0);
	else if (ft_strncmp2(current->tab[0], "exit", 4) == 0)
		return (0);
	return (-1);
}

int	exec_builtin(t_shell *list, char **envp, char *line, t_env *env)
{
	t_cmd	*current;
	// int		l;
	int		i;

	i = 0;
	(void)envp;
	current = list->head;
	if (current->tab[0] == NULL)
		return (-1);
	// l = ft_strlen((current->tab[0]));
	if (ft_strncmp2(current->tab[0], "pwd", 4) == 0)
		return (call_pwd());
	else if ((ft_strncmp2(current->tab[0], "cd", 3) == 0))
		return (call_cd(list, env));
	else if ((ft_strncmp2(current->tab[0], "echo", 4) == 0))
		return (mini_echo(list, current->tab));
	else if ((ft_strncmp2(current->tab[0], "export", 7) == 0))
		return (sort_list(env, current->tab));
	else if (ft_strcmp(current->tab[0], "unset") == 0)
		return (call_unset(env, current->tab));
	else if (ft_strncmp2(current->tab[0], "env", 4) == 0)
		return (printf_env(env, list));
	else if (ft_strncmp2(current->tab[0], "exit", 4) == 0)
		return (mini_exit(list, current->tab[1], line, env));
	return (-1);
}

char	*search_env(t_env *env)
{
	int		i;
	t_env	*curr;

	i = 0;
	curr = env->env_head;
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
			return ((0));
		if (s1[i] != s2[i])
			return (((unsigned char)s1[i] - (unsigned char)s2[i]));
		i++;
	}
	return (-1);
}
