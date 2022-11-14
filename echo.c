#include "minishell.h"

int	mini_echo(t_shell *list, char **command)
{
	int		option;
	int		i;

	if (list->double_quote == 1 || list->single_quote == 1)
		i = 0;
	else
		i = 1;
	option = 0;
	if (command == NULL)
		return (-1);
	while (command[i] && ft_find_sign(command[i]) == 0)
	{
		option = 1;
		i++;
	}
	return_value(list, command);
	print_echo(list, i, option);
	if (option == 1)
	{
		g_exit_status = 0;
		return (0);
	}
	else
		write(1, "\n", 1);
	g_exit_status = 0;
	return (0);
}

// void	check_dollar(char **command, int option, t_shell *list)
// {
// 	int	i;

// 	if (option == 1 && (list->double_quote == 0 && list->single_quote != 1))
// 		i = 2;
// 	else 
// 		i = 1;
// 	while (command[i])
// 	{
// 		if (command[i][0] == '$')
// 		{
// 			if (i == 1)
// 				i = index_check(list, option, i);
// 			execute_dollar(list, i, option, command);
// 			i++;
// 		}
// 		else
// 		{
// 			print_echo(list, i, option);
// 			i++;
// 		}
// 	}
// }

// void	execute_dollar(t_shell *list, int i, int option, char **command)
// {
// 	char	*tmp;
// 	int		j;

// 	tmp = NULL;
// 	j = 0;
// 	if (list->single_quote == 1)
// 		print_echo(list, i, option);
// 	else
// 	{
// 		tmp = ft_substr(command[i], (1), ft_strlen(*command));
// 		dollar_var(list, tmp);
// 	}

// }

int	ft_find_sign(char *command)
{
	int	i;

	i = 0;
	while (command[i])
	{
		if (command[i] == '-' && command[i + 1] == 'n')
			return (0);
		i++;
	}
	return (-1);
}
