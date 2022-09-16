/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:05:26 by qbonvin           #+#    #+#             */
/*   Updated: 2021/11/24 15:44:53 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*pdest;
	unsigned char	*psrc;
	unsigned int	i;

	pdest = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (0);
	while (i < n)
	{
		*pdest = *psrc;
		i++;
		pdest++;
		psrc++;
	}
	return (dst);
}
