/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa_maj.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:13:06 by qbonvin           #+#    #+#             */
/*   Updated: 2022/03/01 09:04:47 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_hexa_maj(unsigned int nb)
{	
	if (nb >= 0 && nb < 10)
		ft_putchar(nb + '0');
	else if (nb >= 10 && nb <= 15)
	{
		if (nb == 10)
			ft_putchar('A');
		if (nb == 11)
			ft_putchar('B');
		if (nb == 12)
			ft_putchar('C');
		if (nb == 13)
			ft_putchar('D');
		if (nb == 14)
			ft_putchar('E');
		if (nb == 15)
			ft_putchar('F');
	}
	else
	{
		ft_putnbr_hexa_maj(nb / 16);
		ft_putnbr_hexa_maj(nb % 16);
	}
	return (ft_len_number(nb));
}
