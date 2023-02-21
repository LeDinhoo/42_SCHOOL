/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:20:10 by hdupuy            #+#    #+#             */
/*   Updated: 2022/12/01 14:21:13 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int			ft_printf(const char *s, ...);
int			ft_wich_type(char type, va_list s_arg);
int			ft_putstr(char *s);
int			ft_putnbr(int nb);
int			ft_putchar(char c);
int			ft_hex(unsigned long long nb, char *base);
int			ft_putunbr(unsigned int nb);

#endif
