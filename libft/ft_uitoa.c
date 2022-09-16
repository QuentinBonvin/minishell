/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:10:39 by qbonvin           #+#    #+#             */
/*   Updated: 2022/04/05 08:54:40 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_number(unsigned long *n)
{
	unsigned int		len;
	long				n2;

	len = 0;
	if (*n == 0)
	{
		len = 1;
	}
	if (*n < 0)
	{
		*n = *n * -1;
		len++;
	}
	n2 = *n;
	while (n2 > 0)
	{
		n2 = n2 / 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char				*string;
	unsigned int		len_str;
	unsigned long		nbr;

	nbr = n;
	len_str = len_number(&nbr);
	string = malloc(sizeof(char) * (len_str + 1));
	if (!string)
		return (0);
	string[len_str] = '\0';
	len_str--;
	if (nbr == 0)
	{
		string[0] = 48;
		return (string);
	}
	if (n < 0)
		string[0] = '-';
	while (nbr > 0)
	{
		string[len_str] = 48 + (nbr % 10);
		nbr = nbr / 10;
		len_str--;
	}
	return (string);
}
