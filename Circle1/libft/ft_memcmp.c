/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:01:40 by hdupuy            #+#    #+#             */
/*   Updated: 2022/11/24 11:22:54 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s3;
	unsigned char	*s4;
	size_t			i;

	i = 0;
	s3 = (unsigned char *) s1;
	s4 = (unsigned char *) s2;
	while (n > 0)
	{
		if (s3[i] != s4[i])
			return (s3[i] - s4[i]);
		i++;
		n--;
	}
	return (0);
}
