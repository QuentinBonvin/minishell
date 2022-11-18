/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:45:27 by qbonvin           #+#    #+#             */
/*   Updated: 2022/11/18 14:45:28 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	mini_echo(t_cmd *current, char **command, t_shell *list)
{
	int		option;
	int		i;

	option = 0;
	i = 0;
	if (command == NULL)
		return (-1);
	while (command[i])
	{
		if (ft_find_sign(command[i]) == 0)
			option = 1;
		i++;
	}
	i = 0;
	if (option == 1 && command[1] == NULL)
		ft_error_print(command);
	else
		print_and_return(current, i, option, list);
	return (0);
}

int	print_and_return(t_cmd *current, int i, int option, t_shell *list)
{
	print_echo(current, i, option, list);
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
	while (command[i])
	{
		if (command[i] == '-' && command[i + 1] == 'n')
			return (0);
		i++;
	}
	return (-1);
}
