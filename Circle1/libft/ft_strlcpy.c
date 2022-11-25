/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:34:04 by hdupuy            #+#    #+#             */
/*   Updated: 2022/11/11 13:44:20 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	sizesrc;

	sizesrc = ft_strlen(src);
	if (dstsize == 0)
		return (sizesrc);
	if (!src)
		return (0);
	i = 0;
	while ((i < dstsize - 1) && (sizesrc >= dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	while ((i < sizesrc) && (sizesrc <= dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (sizesrc);
}
