/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:09:51 by hdupuy            #+#    #+#             */
/*   Updated: 2022/11/24 11:24:37 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

static void	int_char(int nmb, int fd)
{
	char	to_char;

	nmb += 48;
	to_char = (char)nmb;
	write (fd, &to_char, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write (fd, "-", 1);
		write (fd, "2", 1);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		write (fd, "-", 1);
		ft_putnbr_fd(n * -1, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		int_char(n, fd);
	}
}
