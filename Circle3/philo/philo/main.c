/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:46:02 by hdupuy            #+#    #+#             */
/*   Updated: 2023/08/23 20:49:23 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	*philosopher_life(void *arg)
{
	t_philo	*philo;
	bool	is_dead;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 1)
	{
		usleep(500);
	}
	while (1)
	{
		pthread_mutex_lock(philo->print);
		is_dead = *(philo->death);
		pthread_mutex_unlock(philo->print);
		if (is_dead == 1)
			break ;
		eat(philo);
		if (philo->num_times_to_eat > 0
			&& philo->num_eats >= philo->num_times_to_eat)
			break ;
		ft_sleep(philo);
	}
	return (NULL);
}

void	print_routine(t_philo *p, char *action)
{
	bool	is_dead;

	pthread_mutex_lock(p->print);
	is_dead = *(p->death);
	pthread_mutex_unlock(p->print);
	pthread_mutex_lock(p->print);
	if (is_dead == 0)
		printf("%lums %d %s\n", get_timestamp() - p->thread_start, p->id,
			action);
	pthread_mutex_unlock(p->print);
}

void	init_philo_fork(t_main *main, int i)
{
	if (i % 2 == 0)
	{
		main->philo_data[i].left_fork = &main->forks[i];
		main->philo_data[i].right_fork = &main->forks[(i + 1)
			% main->num_philo];
	}
	else
	{
		main->philo_data[i].right_fork = &main->forks[(i + 1)
			% main->num_philo];
		main->philo_data[i].left_fork = &main->forks[i];
	}
}

void	philo(t_main *main)
{
	int			i;
	long int	now;

	i = 0;
	now = get_timestamp();
	main->death = false;
	while (i < main->num_philo)
	{
		init_philo_data(main, i, now);
		init_philo_fork(main, i);
		pthread_create(&main->philo[i], NULL, philosopher_life,
			&(main->philo_data[i]));
		i++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_main	main;

	handle_error(argc, argv);
	init_struct(argc, argv, &main);
	handle_nb_philo(&main);
	init_mutex(&main);
	init_thread(&main);
	philo(&main);
	thread_join(&main);
	thread_destroy(&main);
	pthread_mutex_destroy(&main.print_mutex);
	free_data(&main);
	return (0);
}
