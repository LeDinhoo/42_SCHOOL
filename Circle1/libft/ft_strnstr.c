/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:44:36 by hdupuy            #+#    #+#             */
/*   Updated: 2022/11/17 15:19:39 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t			i;
	size_t			j;

	i = 0;
	if ((!s1 || !s2) && !len)
		return (0);
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] && (i < len))
	{
		j = 0;
		while (s2[j] == s1[j + i] && (i + j) < len)
			if (s2[++j] == '\0')
				return ((char *)&s1[i]);
		i++;
	}
	return (0);
}
