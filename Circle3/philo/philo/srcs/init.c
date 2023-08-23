/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:59:56 by hdupuy            #+#    #+#             */
/*   Updated: 2023/08/23 19:22:47 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_mutex(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->num_philo)
	{
		pthread_mutex_init(&main->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&main->print_mutex, NULL);
}

void	init_thread(t_main *main)
{
	main->philo = malloc(sizeof(pthread_t) * main->num_philo);
	main->philo_data = malloc(sizeof(t_philo) * main->num_philo);
}

void	init_philo_data(t_main *main, int i, long int now)
{
	main->philo_data[i].death = &(main->death);
	main->philo_data[i].id = i + 1;
	main->philo_data[i].last_eat = now;
	main->philo_data[i].num_eats = 0;
	main->philo_data[i].num_times_to_eat = main->num_times_to_eat;
	main->philo_data[i].print = &(main->print_mutex);
	main->philo_data[i].thread_start = now;
	main->philo_data[i].time_to_die = main->time_to_die;
	main->philo_data[i].time_to_eat = main->time_to_eat;
	main->philo_data[i].time_to_sleep = main->time_to_sleep;
}

void	eat(t_philo *philo)
{
	check_death(philo);
	pthread_mutex_lock(philo->left_fork);
	print_routine(philo, FORK);
	check_death(philo);
	pthread_mutex_lock(philo->right_fork);
	check_death(philo);
	print_routine(philo, FORK);
	print_routine(philo, EAT);
	philo->last_eat = get_timestamp();
	ft_usleep(philo->time_to_eat);
	philo->num_eats++;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

int	check_death(t_philo *p)
{
	long int	now;
	bool		is_dead;

	is_dead = *(p->death);
	pthread_mutex_lock(p->print);
	now = get_timestamp() - p->last_eat;
	pthread_mutex_unlock(p->print);
	if (is_dead == 0 && now >= p->time_to_die)
	{
		pthread_mutex_lock(p->print);
		*(p->death) = true;
		printf("%lums %d \x1B[31mDIED\x1B[0m 💀\n", get_timestamp()
			- p->thread_start, p->id);
		pthread_mutex_unlock(p->print);
		return (1);
	}
	return (0);
}
