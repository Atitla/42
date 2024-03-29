/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:56:49 by ecunha            #+#    #+#             */
/*   Updated: 2024/02/21 15:49:49 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stddef.h>
# include <sys/time.h>
# include <pthread.h>

# define PHILO_MAX 200

typedef struct s_mut
{
	pthread_mutex_t	mutex;
	int				variable;
}					t_mut;

typedef struct s_phi
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_mutex;
	pthread_mutex_t	*meal_mutex;
	pthread_mutex_t	*dead_mutex;
	pthread_mutex_t	*start_mutex;
	pthread_mutex_t	*start_time_mutex;
	int				*bool_start;
}					t_phi;

typedef struct s_data
{
	int				args[5];
	int				dead_flag;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	start_mutex;
	pthread_mutex_t	start_time_mutex;
	int				bool_start;
	t_phi			*philos;
}					t_data;

int	ft_atoi(const char *str);

#endif
//number_of_philosophers time_to_die time_to_eat time_to_sleep
//[number_of_times_each_philosopher_must_eat]
