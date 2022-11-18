/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:45:14 by qbonvin           #+#    #+#             */
/*   Updated: 2022/11/18 14:45:15 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_error(char **arg)
{
	printf("%s", arg[0]);
	printf(": ");
	printf("%s", arg[1]);
	printf(": ");
	printf("%s", strerror(errno));
	printf(" ");
	printf("\n");
	g_exit_status = 1;
	return (1);
}

int	ft_error_print(char **arg)
{
	printf("Bash: ");
	printf("%s", arg[0]);
	printf(": ");
	printf("Command not found");
	printf("\n");
	g_exit_status = 127;
	return (1);
}
