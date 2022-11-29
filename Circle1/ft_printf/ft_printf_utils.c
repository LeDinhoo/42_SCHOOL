/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:58:42 by hdupuy            #+#    #+#             */
/*   Updated: 2022/11/29 09:39:47 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

ssize_t	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

int	ft_putstr(char *s)
{
	size_t	idx;

	idx = 0;
	if (!s)
		return (0);
	while (s[idx])
	{
		ft_putchar(s[idx]);
		idx++;
	}
	return (idx);
}

ssize_t	ft_putnbr_printf(int n)
{
	char	*str;
	ssize_t	char_written;

	printf("YO");
	str = ft_itoa(n);
	char_written = write(1, str, ft_strlen(str));
	printf("%s\n%zu\n\n\n\n\n", str, char_written);
	free(str);
	return (char_written);
}
