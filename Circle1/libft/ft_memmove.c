/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:55:07 by hdupuy            #+#    #+#             */
/*   Updated: 2022/11/09 18:53:41 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*tmp;

	tmp = (unsigned char *)src;
	dst = (unsigned char *)dest;
	if (tmp < dst)
	{
		while (n--)
			dst[n] = tmp[n];
	}
	else
		ft_memcpy(dst, tmp, n);
	return (dst);
}
