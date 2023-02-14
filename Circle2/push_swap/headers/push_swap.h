/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:00:01 by hdupuy            #+#    #+#             */
/*   Updated: 2023/02/10 06:55:35 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_num
{
	int				content;
	struct s_num	*next;
	int				index;
}	t_num;

typedef struct s_top
{
	struct s_num	*first;
}	t_top;

int	ft_sort_pa(t_top *top_a, t_top *top_b);
int	ft_sort_pb(t_top *top_a, t_top *top_b);
int	ft_sort_rra(t_top *top);
int	ft_sort_rrb(t_top *top);
int	ft_sort_rrr(t_top *top_a, t_top *top_b);
int	ft_sort_ra(t_top *top);
int	ft_sort_rb(t_top *top);
int	ft_sort_rr(t_top *top_a, t_top *top_b);
int	ft_sort_sa(t_top *top);
int	ft_sort_sb(t_top *top);
int	ft_sort_ss(t_top *top_a, t_top *top_b);
int	ft_num_add(t_top *num, int nb);
int	ft_num_addback(t_top *num, int nb);
int	ft_print_list(t_top *top);
int	ft_create_list(int size, char **argv, t_top *top, t_num *new);
int	ft_size_list(t_top *top);

int	ft_put_index(t_top *top);
int	ft_sort_radix(t_top *top_a, t_top *top_b);
int	ft_check_sort(t_top *top);

#endif
