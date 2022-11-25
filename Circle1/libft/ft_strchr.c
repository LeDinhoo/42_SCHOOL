/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:00:41 by hdupuy            #+#    #+#             */
/*   Updated: 2022/11/17 15:05:12 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	size_t			len;
	unsigned char	c2;

	len = ft_strlen(s);
	c2 = c;
	i = 0;
	while (i <= len)
	{
		if (c2 == s[i])
			return ((char *)s + i);
		i++;
	}
	return (0);
}
