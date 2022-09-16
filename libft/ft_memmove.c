/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 08:17:53 by qbonvin           #+#    #+#             */
/*   Updated: 2021/11/23 10:26:35 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*pdst;
	unsigned char	*psrc;
	unsigned char	*lasts;
	unsigned char	*lastd;

	pdst = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	if (pdst == psrc)
		return (NULL);
	if (pdst < psrc)
	{
		while (len--)
			*pdst++ = *psrc++;
	}
	else
	{
		lasts = psrc + (len - 1);
		lastd = pdst + (len - 1);
		while (len > 0)
		{
			*lastd-- = *lasts--;
			len--;
		}
	}
	return (dst);
}
