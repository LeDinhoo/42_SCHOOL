/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:59:32 by hdupuy            #+#    #+#             */
/*   Updated: 2023/08/23 20:53:13 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long int	get_timestamp(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

int	ft_usleep(long int time)
{
	long int	start_time;

	start_time = get_timestamp();
	while ((get_timestamp() - start_time) < time)
		usleep(150);
	return (1);
}

int	handle_nb_philo(t_main *main)
{
	if (main->num_philo < 1 || main->num_philo > MAX_PHILO)
	{
		printf("Invalid number of philosophers. ");
		printf("It should be between 1 and %d.\n", MAX_PHILO);
		exit(EXIT_FAILURE);
	}
	return (1);
}

int	handle_error(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Usage: %s number_of_philosophers time_to_die", argv[0]);
		printf("time_to_eat time_to_sleep");
		printf(" [number_of_times_each_philosopher_must_eat]\n");
		exit(EXIT_FAILURE);
	}
	return (1);
}

void	init_struct(int argc, char **argv, t_main *main)
{
	main->num_philo = ft_atoi(argv[1]);
	main->time_to_die = ft_atoi(argv[2]);
	main->time_to_eat = ft_atoi(argv[3]);
	main->time_to_sleep = ft_atoi(argv[4]);
	if (main->num_philo == 1)
	{
		handle_one_philo(main);
		exit(0);
	}
	else
	{
		if (argc == 6)
			main->num_times_to_eat = ft_atoi(argv[5]);
		else
			main->num_times_to_eat = -1;
		if (main->num_philo > 0 && main->num_philo < 201)
			main->forks = malloc(sizeof(pthread_mutex_t) * main->num_philo);
	}
}
