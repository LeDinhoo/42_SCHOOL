/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:35:07 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/05 10:35:37 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_sep(char c, char charset)
{
	if (charset == c)
		return (1);
	if (c == '\0')
		return (1);
	return (0);
}

static int	ft_nbr_words(char *str, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 1;
	count = 0;
	while (str[i])
	{
		if (((ft_char_sep(str[i], c) == 0))
			&& ((ft_char_sep(str[j], c) == 1)))
			count++;
		if (str[j] == '\0')
			break ;
		i++;
		j++;
	}
	return (count);
}

static void	*ft_free(char **tab, size_t idx)
{
	while (idx > 0)
	{
		idx--;
		free(tab[idx]);
	}
	free(tab);
	return (NULL);
}

static char	**ft_fill_malloc(char *s, char c, char **tab, size_t count)
{
	size_t	i;
	size_t	j;
	size_t	l_words;

	i = 0;
	j = 0;
	while (j < count)
	{
		while (s[i] && (ft_char_sep(s[i], c) == 1))
			i++;
		s += i;
		i = 0;
		while ((ft_char_sep(s[i++], c) == 0))
		l_words = i;
		tab[j] = ft_substr(s, 0, l_words);
		if (!tab[j])
			return (ft_free(tab, j));
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char *s, char c)
{
	size_t		count;
	char		**tab;

	if (!s)
		return (NULL);
	count = ft_nbr_words(s, c);
	tab = malloc(sizeof(char *) * (count + 1));
	if (!(tab))
		return (NULL);
	tab = ft_fill_malloc(s, c, tab, count);
	return (tab);
}
