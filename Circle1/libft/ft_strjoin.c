/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:58:18 by hdupuy            #+#    #+#             */
/*   Updated: 2022/11/17 15:21:38 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	ssize_t	index;
	size_t	start;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	index = -1;
	start = (ft_strlen(s1) - 1);
	result = malloc(sizeof(char) * (ft_strlen(s2) + start + 2));
	if (!result)
		return (NULL);
	while (s1[++index])
		result[index] = s1[index];
	index = -1;
	while (s2[++index])
		result[++start] = s2[index];
	result[++start] = '\0';
	return (result);
}
