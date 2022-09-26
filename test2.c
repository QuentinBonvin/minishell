/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:42:09 by nnemeth           #+#    #+#             */
/*   Updated: 2022/09/26 14:29:29 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define TOKEN_DELIM "| '' "" "

unsigned int	is_delim(char c, char *delim)
{
	while (*delim != '\0')
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

char	*my_strtok(char *str, char *delim)
{
	static char	*tmp;

	if (!str)
		str = tmp;
	if (!str)
		return (NULL);
	while (1)
	{
		if (is_delim(*str, delim))
		{
			str++;
			continue ;
		}
		if (*str == '\0')
			return (NULL);
		break ;
	}
	char	*ret = str;
    while (1)
	{
		if (*str == '\0')
		{
            tmp = str;
            return (ret);
		}
        if (is_delim(*str, delim))
		{
			*str = '\0';
			tmp = str + 1;
			return (ret);
		}
		str++;
	}
}

// int main()
// {
//     char srcString[] = "HI'AticleworldR|eader";
//     char *token = my_strtok(srcString, TOKEN_DELIM);
//     while(token)
//     {
//         printf("%s\n", token);
//         token = my_strtok(NULL, TOKEN_DELIM);
//     }
//     return 0 ;
// }
