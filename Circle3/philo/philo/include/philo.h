/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:09:50 by hdupuy            #+#    #+#             */
/*   Updated: 2023/08/23 20:54:00 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define MAX_PHILO 200

# define RESET "\x1B[0m"
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define BLUE "\x1B[34m"
# define MAGENTA "\x1B[35m"
# define CYAN "\x1B[36m"

# define FORK "\x1B[32mhas taken a fork\x1B[0m 🥢"
# define EAT "\x1B[36mis eating\x1B[0m 🍙"
# define SLEEP "\x1B[33mis sleeping\x1B[0m 🌒"
# define THINK "\x1B[34mis thinking\x1B[0m 🧠"

typedef struct s_philo
{
	bool			*death;
	int				id;
	int				num_eats;
	int				num_times_to_eat;
	int				time_to_eat;
	int				time_to_sleep;
	long int		last_eat;
	long int		thread_start;
	long int		time_to_die;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*print;
	pthread_mutex_t	*right_fork;
}					t_philo;

typedef struct s_main
{
	bool			death;
	int				num_philo;
	int				num_times_to_eat;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_t		*philo;
	t_philo			*philo_data;
}					t_main;

int					check_death(t_philo *p);
int					ft_atoi(const char *str);
int					ft_usleep(long int time);
int					handle_error(int argc, char **argv);
int					handle_nb_philo(t_main *main);
long int			get_timestamp(void);
long int			get_timestamp(void);
void				*philosopher_life(void *arg);
void				eat(t_philo *philo);
void				free_data(t_main *main);
void				ft_sleep(t_philo *philo);
void				init_mutex(t_main *main);
void				init_philo_data(t_main *main, int i, long int now);
void				init_struct(int argc, char **argv, t_main *main);
void				init_thread(t_main *main);
void				philo(t_main *main);
void				print_routine(t_philo *p, char *action);
void				thread_destroy(t_main *main);
void				thread_join(t_main *main);
void				handle_one_philo(t_main *main);

#endif