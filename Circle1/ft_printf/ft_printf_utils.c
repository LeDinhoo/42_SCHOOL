/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:58:42 by hdupuy            #+#    #+#             */
/*   Updated: 2022/11/28 19:31:39 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int	ft_putchar(char c)
{
	if (write (1, &c, 1))
		return (1);
	return (0);
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

void	ft_int_char(int nmb)
{
	char	to_char;

	nmb += 48;
	to_char = (char)nmb;
	write (1, &to_char, 1);
}

int	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write (1, "-", 1);
		write (1, "2", 1);
		ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		write (1, "-", 1);
		ft_putnbr(n * -1);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		ft_int_char(n);
	}
	return (0);
}
