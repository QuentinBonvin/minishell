#include "minishell.h"

int	call_cd(t_shell *list)
{
	char *home;
	int res;
	char *pwd;
	// char *test;

	home = get_env("HOME", list);
	pwd = get_env("PWD", list);
	res = chdir(home);
	// printf("home: %s\n", home);
	// test = getcwd(NULL, 0);
	if (res == -1)
	{
		ft_putstr("cd: ");
		ft_putstr(list->head->prev->content);
		ft_putstr(": No such file or directory\n");
	}
	else /*(res == 0)*/
	{
		printf("oldpwd: %s\n", pwd);
		printf("pwd: %s\n", home);
		set_env("OLDPWD", pwd, list);
		set_env("PWD", home, list);
	}
	pwd = getcwd(NULL,0);
	// printf("pwd: %s\n", pwd);
	return (res);
}

char	*get_env(char *name, t_shell *list)
{
	t_env *curr;
	char *home;
	int	l;

	curr = list->env_head;
	l = ft_strlen(name) + 1;
	while (curr != NULL)
	{
		if ((ft_strncmp2(curr->content, name, l)) == 0)
		{
			home = join_home(curr->content, l);
			return (home);
		}
		curr = curr->prev;
	}
	return (0);
}

char	*join_home(char *curr, int length)
{
	char 	*home;
	size_t	end;

	end = ft_strlen(curr);
	home = ft_substr(curr, length, end);
	return (home);
}

int	set_env(char *name, char *pwd, t_shell *list)
{
	char	*var_ok;
	char *tmp;

	tmp = ft_strjoin(name, "=");
	var_ok = env_ok(tmp, list);
	if (var_ok == NULL)
	{	
		printf("add to env");
	}
	else
	{
		var_ok = ft_strjoin(tmp, pwd);
		// printf("var_ok after join: %s\n", var_ok);
	}
	return (0);
}

char	*env_ok(char *name, t_shell *list)
{
	t_env *curr;
	int	l;

	curr = list->env_head;
	l = ft_strlen(name) + 1;
	while (curr != NULL)
	{
		if ((ft_strncmp2(curr->content, name, l)) == 0)
		{

			return (curr->content);
		}
		curr = curr->prev;
	}
	return (NULL);
}