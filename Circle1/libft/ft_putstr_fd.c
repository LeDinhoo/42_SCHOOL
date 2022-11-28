/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:32:17 by hdupuy            #+#    #+#             */
/*   Updated: 2022/11/28 14:50:01 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	idx;

	idx = 0;
	if (!s)
		return ;
	while (s[idx])
	{
		ft_putchar(s[idx], fd);
		idx++;
	}
}
