/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:08:37 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/03 15:44:12 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

ssize_t	ft_strichr(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
		if (s[i++] == (char)c)
			return (i - 1);
	return (-1);
}

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
