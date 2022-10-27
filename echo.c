#include "minishell.h"

void	mini_echo(t_shell *list, char *command)
{
	int		option;
	int		i;

	i = -1;
	option = 0;
	if (command == NULL)
		return ;
	i = ft_find_sign(command);
	while (command[i] && (command[i + 1] == 'n'))
	{
		option = 1;
		i++;
	}
	i = 0;
	if (command[0] == '$')
		execute_dollar(list, i, option, command);
	else
		print_echo(list, i, option);
}

void	execute_dollar(t_shell *list, int i, int option, char *command)
{
	char	*tmp;

	tmp = NULL;
	if (list->single_quote == 1)
		print_echo(list, i, option);
	else
	{
		tmp = ft_substr(command, (i + 1), ft_strlen(command - 1));
		dollar_var(list, tmp);
	}
}

int	print_echo(t_shell *list, int i, int option)
{
	t_cmd	*curr;

	curr = list->head;
	if (option == 1)
		i = 2;
	else
		i = 1;
	while (curr)
	{
		while (curr->tab[i])
		{
			ft_putstr(curr->tab[i]);
			ft_putstr(" ");
			i++;
		}
		curr = curr->prev;
	}
	if (option == 1)
		return (0);
	else
		write(1, "\n", 1);
	return (0);
}

int	ft_find_sign(char *command)
{
	int	i;

	i = 0;
	while (command[i])
	{
		if (command[i] == '-')
			break ;
		i++;
	}
	return (i);
}

void	dollar_var(t_shell *list, char *var)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = check_if_in_env(list, var);
	if (tmp == NULL)
		return ;
	while (tmp[i] && tmp != NULL)
	{
		if (tmp[i] == '=')
			break ;
		i++;
	}
	tmp = ft_substr(tmp, (i + 1), ft_strlen(tmp));
	printf("%s\n", tmp);
}
