/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:09:50 by hdupuy            #+#    #+#             */
/*   Updated: 2023/08/22 18:20:34 by hdupuy           ###   ########.fr       */
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

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "DIED"

typedef struct s_philo
{
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long int		time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_eats;
	int				num_times_to_eat;
	pthread_mutex_t	print;
	long int		last_eat;
	long int		thread_start;
}					t_philo;

typedef struct s_main
{
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*forks;
	pthread_t		*philo;
	t_philo			*philo_data;
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_times_to_eat;
}					t_main;

int					ft_atoi(const char *str);
long int			get_timestamp(void);
long int			get_timestamp(void);
int					ft_usleep(long int time);
int					handle_nb_philo(t_main *main);
int					handle_error(int argc, char **argv);
void				init_struct(int argc, char **argv, t_main *main);
void				init_mutex(t_main *main);
void				init_thread(t_main *main);
void				ft_sleep(t_philo *philo);
void				eat(t_philo *philo);
int					check_death(t_philo *p);
void				*philosopher_life(void *arg);
void				print_routine(t_philo *p, char *action);
void				philo(t_main *main);
void				thread_join(t_main *main);
void				thread_destroy(t_main *main);
void				free_data(t_main *main);

#endif