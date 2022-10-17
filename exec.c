#include "minishell.h"

int	call_cd(char *aux, t_shell *list)
{
	char *home;
	int res;
	char *pwd;

	(void)aux;
	home = get_env("HOME", list);
	pwd = get_env("PWD", list);
	// printf("pwd: %s\n", pwd);
	// printf("home: %s\n", home);
	res = chdir(home);
	if (res == 0)
	{
		printf("ok until now");
		// set_env("OLDPWD", pwd, list);
		// set_env("PWD", home, list);
	}
	return (0);
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

// int	set_env(char *name, t_shell *list)
// {

// }