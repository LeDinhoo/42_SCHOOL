/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:15:35 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/05 14:48:33 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		j;
	char		*dest;

	i = start;
	j = 0;
	if (!s || start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(&s[start]))
		dest = malloc(sizeof(char) * (ft_strlen(&s[start]) + 1));
	else
		dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (free(dest), NULL);
	while (s[i] && j < len)
	{
		dest[j] = s[i];
		i++;
		j++;
	}
	dest[j] = 0;
	return (free(s), dest);
}
