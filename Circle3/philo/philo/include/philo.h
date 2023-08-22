/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:09:50 by hdupuy            #+#    #+#             */
/*   Updated: 2023/08/22 09:12:00 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define MAX_PHILO 200

typedef struct s_philo
{
	int						id;
	pthread_mutex_t			*left_fork;
	pthread_mutex_t			*right_fork;
	pthread_mutex_t			want_eat;
	long long unsigned int	time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						num_eats;
	int						num_times_to_eat;
	unsigned long long int	last_eat;
}							t_philo;

typedef struct s_main
{
	pthread_mutex_t			*forks;
	pthread_t				*philo;
	t_philo					*philo_data;
	int						num_philo;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						num_times_to_eat;
}							t_main;

int							ft_atoi(const char *str);
long int					get_timestamp(void);

#endif