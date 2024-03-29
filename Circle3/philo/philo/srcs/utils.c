/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:56:24 by hdupuy            #+#    #+#             */
/*   Updated: 2023/08/23 20:03:04 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	signe;

	i = 0;
	signe = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-')
	{
		signe *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * signe);
}

void	thread_join(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->num_philo)
	{
		pthread_join(main->philo[i], NULL);
		i++;
	}
}

void	thread_destroy(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->num_philo)
	{
		pthread_mutex_destroy(&main->forks[i]);
		i++;
	}
}

void	ft_sleep(t_philo *philo)
{
	int	wake_time;
	int	death_time;

	wake_time = (get_timestamp() - philo->last_eat) + philo->time_to_sleep;
	death_time = (get_timestamp() - philo->last_eat) + philo->time_to_die;
	check_death(philo);
	print_routine(philo, SLEEP);
	if (wake_time >= death_time)
		ft_usleep(philo->time_to_die);
	else
		ft_usleep(philo->time_to_sleep);
	check_death(philo);
	print_routine(philo, THINK);
}

void	free_data(t_main *main)
{
	free(main->forks);
	free(main->philo);
	free(main->philo_data);
}
