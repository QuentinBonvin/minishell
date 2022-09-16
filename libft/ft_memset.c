/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 08:13:09 by qbonvin           #+#    #+#             */
/*   Updated: 2021/11/23 09:25:55 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*memory;

	memory = (unsigned char *)b;
	while (len > 0)
	{
		*memory = (unsigned char)c;
		memory++;
		len--;
	}
	return (b);
}
