#include "minishell.h"

int	print_echo(t_shell *list, int i, int option)
{
	t_cmd	*curr;

	(void)option;
	curr = list->head;
	if (option == 1 && (list->double_quote == 0 && list->single_quote == 0))
		i = 2;
	else if (option == 1
		&& (list->double_quote == 1 || list->single_quote == 1))
		i = 1;
	else
		i = 1;
	while (curr)
	{
		while (curr->tab[i])
		{
			printer(curr->tab[i], list);
			i++;
		}
		curr = curr->prev;
	}
	return (0);
}

void	printer(char *command, t_shell *list)
{
	ft_putstr(command);
	if (list->double_quote == 1 || list->single_quote == 1)
		return ;
	else
	{
		ft_putstr(" ");
		return ;
	}
}

char	*dollar_var(t_shell *list, char *var, t_env *env)
{
	char	*tmp;
	int		i;

	i = 0;
	(void)list;
	tmp = check_if_in_env(env, var);
	if (tmp == NULL)
		return (0);
	while (tmp[i] && tmp != NULL)
	{
		if (tmp[i] == '=')
			break ;
		i++;
	}
	tmp = ft_substr(tmp, (i + 1), ft_strlen(tmp));
	return (tmp);
}

int	index_check(t_shell *list, int option, int i)
{
	if ((list->double_quote == 0 && list->single_quote == 0) && option == 1)
		i = 2;
	else
		i = 1;
	return (i);
}
