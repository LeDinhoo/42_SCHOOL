/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:46:02 by hdupuy            #+#    #+#             */
/*   Updated: 2023/08/22 18:25:21 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	*philosopher_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 1)
	{
		usleep(500);
	}
	while (1)
	{
		eat(philo);
		ft_sleep(philo);
	}
	return (NULL);
}

void	print_routine(t_philo *p, char *action)
{
	pthread_mutex_lock(&p->print);
	printf("%lums %d %s\n", get_timestamp() - p->thread_start, p->id, action);
	pthread_mutex_unlock(&p->print);
}

void	philo(t_main *main)
{
	int			i;
	long int	now;

	i = 0;
	now = get_timestamp();
	while (i < main->num_philo)
	{
		main->philo_data[i].id = i + 1;
		main->philo_data[i].time_to_die = main->time_to_die;
		main->philo_data[i].time_to_eat = main->time_to_eat;
		main->philo_data[i].time_to_sleep = main->time_to_sleep;
		main->philo_data[i].num_eats = 0;
		main->philo_data[i].num_times_to_eat = main->num_times_to_eat;
		main->philo_data[i].thread_start = now;
		main->philo_data[i].last_eat = now;
		main->philo_data[i].print = main->print_mutex;
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
		pthread_create(&main->philo[i], NULL, philosopher_life,
			&main->philo_data[i]);
		i++;
	}
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
