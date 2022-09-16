/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:33:32 by qbonvin           #+#    #+#             */
/*   Updated: 2021/11/16 10:41:08 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (set[j] != '\0')
	{
		if (set[j] == s1[i])
			return (1);
		else
			j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	if (s1 == NULL)
		return (0);
	end = ft_strlen(s1) - 1;
	while (ft_set(&s1[start], set) && (s1[start] != '\0'))
	{
		start++;
	}
	while (ft_set(&s1[end], set) && (end > 0))
		end--;
	return (ft_substr(s1, start, end - start + 1));
}
