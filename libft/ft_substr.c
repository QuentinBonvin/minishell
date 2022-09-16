/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 08:21:13 by qbonvin           #+#    #+#             */
/*   Updated: 2021/11/25 15:37:36 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*newstr;
	unsigned int	len_mem;
	unsigned int	index;

	if (!s)
		return (0);
	index = 0;
	len_mem = ft_strlen(&s[start]);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len_mem < len)
		len = len_mem;
	newstr = malloc (len + 1);
	if (!newstr)
		return (NULL);
	while (s[start + index] && index < len)
	{
		newstr[index] = s[start + index];
		index++;
	}
	newstr[index] = '\0';
	return (newstr);
}
