#include "minishell.h"

int	mini_echo(t_shell *list, char **command)
{
	int		option;
	int		i;

	option = 0;
	i = 0;
	printf("command: %s\n", command);
	if (command == NULL)
		return (-1);
	while (command[i])
	{
		if (ft_find_sign(command[i]) == 0)
			option = 1;
		i++;
	}
	// return_value(list, command);
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

int	ft_find_sign(char *command)
{
	int	i;

	i = 0;
	printf("command: %s\n", command);
	while (command[i])
	{
		if (command[i] == '-' && command[i + 1] == 'n')
			return (0);
		i++;
	}
	return (-1);
}
