/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:09:41 by qbonvin           #+#    #+#             */
/*   Updated: 2022/05/23 17:14:19 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	nbr_element;

	nbr_element = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		nbr_element++;
	}
	return (nbr_element);
}
