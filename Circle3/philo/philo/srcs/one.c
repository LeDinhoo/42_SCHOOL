/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:53:40 by hdupuy            #+#    #+#             */
/*   Updated: 2023/08/29 12:40:24 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	handle_one_philo(t_main *main)
{
	int	now;

	now = main->time_to_die;
	printf("0ms 1 \x1B[32mhas taken a fork\x1B[0m 🥢\n");
	usleep(now);
	printf("%dms 1 \x1B[31mDIED\x1B[0m 💀\n", now);
}
