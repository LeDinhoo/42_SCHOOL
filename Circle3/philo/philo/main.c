/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:46:02 by hdupuy            #+#    #+#             */
/*   Updated: 2023/08/11 10:09:41 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t		print_mutex;

unsigned long long	get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((unsigned long long)tv.tv_sec) * 1000
		+ ((unsigned long long)tv.tv_usec) / 1000);
}

void	ft_usleep(int ms)
{
	long int	time;

	time = get_timestamp();
	while (get_timestamp() - time < ms)
		usleep(ms / 10);
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
	if (argc == 6)
		main->num_times_to_eat = ft_atoi(argv[5]);
	else
		main->num_times_to_eat = -1;
	if (main->num_philo > 0 && main->num_philo < 201)
		main->forks = malloc(sizeof(pthread_mutex_t) * main->num_philo);
}

void	init_mutex(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->num_philo)
	{
		pthread_mutex_init(&main->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&print_mutex, NULL);
}

void	init_thread(t_main *main)
{
	main->philo = malloc(sizeof(pthread_t) * main->num_philo);
	main->philo_data = malloc(sizeof(t_philo) * main->num_philo);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	printf("%llu %d has taken a fork\n", get_timestamp(), philo->id);
	pthread_mutex_lock(philo->right_fork);
	printf("%llu %d has taken a fork\n", get_timestamp(), philo->id);
	printf("%llu %d is eating\n", get_timestamp(), philo->id);
	pthread_mutex_lock(&philo->want_eat);
	philo->last_eat = (unsigned long long int)get_timestamp();
	pthread_mutex_unlock(&philo->want_eat);
	ft_usleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	printf("%llu %d is sleeping\n", get_timestamp(), philo->id);
	ft_usleep(philo->time_to_sleep);
	printf("%llu %d is thinking\n", get_timestamp(), philo->id);
}

void	*philosopher_life(void *arg)
{
	t_philo				*philo;
	unsigned long long	last_meal_time;
	int					num_eats;
	unsigned long long	current_time;

	philo = (t_philo *)arg;
	last_meal_time = get_timestamp();
	num_eats = 0;
	while (1)
	{
		if (philo->num_times_to_eat > 0 && num_eats >= philo->num_times_to_eat)
			break ;
		pthread_mutex_lock(&print_mutex);
		current_time = get_timestamp();
		pthread_mutex_unlock(&print_mutex);
		if (current_time - last_meal_time >= philo->time_to_die)
		{
			pthread_mutex_lock(&print_mutex);
			printf("%llu %d died\n", current_time, philo->id);
			pthread_mutex_unlock(&print_mutex);
			break ;
		}
		eat(philo);
		last_meal_time = philo->last_eat;
		num_eats++;
	}
	return (NULL);
}

void	philo(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->num_philo)
	{
		main->philo_data[i].id = i + 1;
		main->philo_data[i].time_to_die = main->time_to_die;
		main->philo_data[i].time_to_eat = main->time_to_eat;
		main->philo_data[i].time_to_sleep = main->time_to_sleep;
		main->philo_data[i].num_eats = 0;
		main->philo_data[i].num_times_to_eat = main->num_times_to_eat;
		pthread_mutex_init(&main->philo_data[i].want_eat, NULL);
		if (i % 2 == 0)
		{
			main->philo_data[i].left_fork = &main->forks[i];
			main->philo_data[i].right_fork = &main->forks[(i + 1)
				% main->num_philo];
		}
		else
		{
			main->philo_data[i].left_fork = &main->forks[(i + 1)
				% main->num_philo];
			main->philo_data[i].right_fork = &main->forks[i];
		}
		pthread_create(&main->philo[i], NULL, philosopher_life,
			&main->philo_data[i]);
		i++;
	}
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

void	free_data(t_main *main)
{
	free(main->forks);
	free(main->philo);
	free(main->philo_data);
}

int	main(int argc, char **argv)
{
	t_main main;

	handle_error(argc, argv);
	init_struct(argc, argv, &main);
	handle_nb_philo(&main);
	init_mutex(&main);
	init_thread(&main);
	philo(&main);
	thread_join(&main);
	thread_destroy(&main);
	pthread_mutex_destroy(&print_mutex);
	free_data(&main);
	return (0);
}