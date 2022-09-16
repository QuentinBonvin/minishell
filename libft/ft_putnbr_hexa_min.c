/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa_min.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:41:45 by qbonvin           #+#    #+#             */
/*   Updated: 2022/03/01 09:04:58 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_hexa_min(unsigned long int nb)
{	
	char	*hexa;

	hexa = "0123456789abcdef";
	if (nb >= 0 && nb <= 15)
	{
		ft_putchar(hexa[nb]);
	}
	else
	{
		ft_putnbr_hexa_min(nb / 16);
		ft_putnbr_hexa_min(nb % 16);
	}
	return (ft_len_number(nb));
}
