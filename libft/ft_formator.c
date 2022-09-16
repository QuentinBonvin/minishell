/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 09:42:42 by qbonvin           #+#    #+#             */
/*   Updated: 2022/03/01 09:03:26 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_formator(va_list args, const char format, int count)
{
	if (format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (format == 'x')
		count += ft_putnbr_hexa_min(va_arg(args, unsigned int));
	else if (format == 'X')
		count += ft_putnbr_hexa_maj(va_arg(args, unsigned int));
	else if (format == 'p')
	{
		count += ft_putstr("0x");
		count += ft_putnbr_hexa_min(va_arg(args, unsigned long int));
	}
	else if (format == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (format == '%')
		count += ft_putchar('%');
	return (count);
}
