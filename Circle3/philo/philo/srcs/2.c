/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:59:56 by hdupuy            #+#    #+#             */
/*   Updated: 2023/08/22 18:25:01 by hdupuy           ###   ########.fr       */
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

void	ft_sleep(t_philo *philo)
{
	check_death(philo);
	print_routine(philo, SLEEP);
	ft_usleep(philo->time_to_sleep);
	check_death(philo);
	print_routine(philo, THINK);
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

	pthread_mutex_lock(&p->print);
	now = get_timestamp() - p->last_eat;
	pthread_mutex_unlock(&p->print);
	if (now >= p->time_to_die)
	{
		print_routine(p, DIE);
		pthread_mutex_lock(&p->print);
		exit(0);
	}
	return (0);
}
