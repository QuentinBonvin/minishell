/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:50:05 by qbonvin           #+#    #+#             */
/*   Updated: 2022/03/01 09:05:09 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_unsigned(unsigned int nb)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_uitoa(nb);
	len = ft_putstr(num);
	free(num);
	return (len);
}
