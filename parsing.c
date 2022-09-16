/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:03:37 by qbonvin           #+#    #+#             */
/*   Updated: 2022/09/16 14:56:59 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	split_argument(int argc, char **argv)
{
	(void)argc;
	int		i;
	char	**argument;
	
	i = 1;
	while (*argv[i])
	{
		argument = ft_split(argv[i], ' ');
		printf("%s\n", argument[i]);
		i++;
	}
	
}