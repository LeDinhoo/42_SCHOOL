/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:29:00 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/05 10:42:38 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	index;
	size_t	len;
	char	*result;

	len = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (free(result), free(s1), NULL);
	index = 0;
	while (s1 && s1[index])
	{
		result[index] = s1[index];
		index++;
	}
	len = 0;
	while (s2 && s2[len])
	{
		result[index + len] = s2[len];
		len++;
	}
	result[index + len] = '\0';
	return (free(s1), result);
}
