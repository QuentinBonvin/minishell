#include "minishell.h"

int	call_cd(t_shell *list, t_env *env)
{
	char	*home;
	int		res;
	char	*pwd;
	char	*arg;
	int		i;

	i = 0;
	res = 0;
	arg = list->head->tab[1];
	pwd = get_env("PWD", env);
	home = get_env("HOME", env);
	if (arg)
	{
		if (arg[i] == '~')
			{
				res = chdir(home);
				return (res);
			}
		res = chdir(arg);
		{
			if (res != 0)
				ft_error_cd(arg);
		}
		home = getcwd(NULL, 0);
		set_env("OLDPWD", pwd, env);
		set_env("PWD", home, env);
	}
	else if (!arg)
	{
		res = chdir(home);
		set_env("PWD", home, env);
		set_env("OLDPWD", pwd, env);
	}
	pwd = getcwd(NULL, 0);
	return (res);
}

char	*get_env(char *name, t_env *env)
{
	t_env	*curr;
	char	*home;
	int		l;
	int		i;

	i = 0;
	curr = env->env_head;
	l = ft_strlen(name) + 1;
	home = NULL;
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

int	set_env(char *name, char *pwd, t_env *env)
{
	char	*var_ok;
	char	*tmp;
	char	*new;

	tmp = ft_strjoin(name, "=");
	var_ok = check_if_in_env(env, tmp);
	if (var_ok != NULL)
	{
		new = ft_strjoin(tmp, pwd);
		replace_in_env(env, var_ok, new);
	}
	return (0);
}

void	ft_error_cd(char *arg)
{
	printf("bash: cd: %s", arg);
	printf(" : No such file or directory\n");
}
