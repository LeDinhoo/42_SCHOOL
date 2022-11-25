/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:08:37 by hdupuy            #+#    #+#             */
/*   Updated: 2022/11/25 11:16:43 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
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
		return (NULL);
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
	if (s1)
		free(s1);
	result[index + len] = '\0';
	return (result);
}
