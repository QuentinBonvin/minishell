#include "minishell.h"

int	call_cd(t_shell *list)
{
	char	*home;
	int		res;
	char	*pwd;
	char	*arg;
	int		i;

	i = 0;
	res = 0;
	arg = list->head->tab[1];
	pwd = get_env("PWD", list);
	home = get_env("HOME", list);
	// printf("pwd: %s\n", pwd);
	if (arg)
	{
		if (arg[i] == '~')
			{
				res = chdir(home);
				return (res);
			}
		res = chdir(home);
		{
			if (res != 0)
				ft_error_cd(arg);
		}
		home = getcwd(NULL, 0);
		set_env("OLDPWD", pwd, list);
		set_env("PWD", home, list);
		printf("home; %s\n", home);
		printf("pwd; %s\n", pwd);
	}
	else if (!arg)
	{
		res = chdir(home);
		printf("home; %s\n", home);
		printf("pwd; %s\n", pwd);
		set_env("PWD", home, list);
		set_env("OLDPWD", pwd, list);
	}
	return (res);
}

char	*get_env(char *name, t_shell *list)
{
	t_env	*curr;
	char	*home;
	int		l;
	int		i;

	i = 0;
	curr = list->env_head;
	l = ft_strlen(name) + 1;
	while (curr != NULL)
	{
		if ((name[i] == '=' || name[i] == '\0') && (curr->content[i] == '='))
			break ;
		if (curr->content[i] == name[i])
		{
			i++;
		}
		else
		{
			curr = curr->prev;
			i = 0;
		}
	}
	home = join_home(curr->content, l);
	// printf("home: %s\n", home);
	return (home);
}

char	*join_home(char *curr, int length)
{
	char	*home;
	size_t	end;

	end = ft_strlen(curr);
	home = ft_substr(curr, length, end);
	return (home);
}

int	set_env(char *name, char *pwd, t_shell *list)
{
	char	*var_ok;
	char	*tmp;
	char	*new;

	tmp = ft_strjoin(name, "=");
	var_ok = check_if_in_env(list, tmp);
	if (var_ok != NULL)
	{
		new = ft_strjoin(tmp, pwd);
		replace_in_env(list, var_ok, new);
	}
	return (0);
}

void	ft_error_cd(char *arg)
{
	printf("bash: cd: %s", arg);
	printf(" : No such file or directory\n");
}
