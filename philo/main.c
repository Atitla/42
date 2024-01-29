/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:18:01 by ecunha            #+#    #+#             */
/*   Updated: 2024/01/29 19:10:22 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < milliseconds)
		usleep(100);
	return (0);
}

int	check_params(char **argv, t_data *data, int flag)
{
	int	i;

	i = 0;
	while (++i <= (4 + flag))
	{
		data->args[i - 1] = ft_atoi(argv[i]);
		if (data->args[i - 1] <= 0)
		{
			return (write(2, "Philo : Wrong number in argument ", 34), \
				printf("%i\n", i), 1);
		}
	}
	if (data->args[0] > PHILO_MAX)
		return (write(2, "Philo : Too many philosophers\n", 30), 1);
	return (0);
}

int	init_params(int argc, char **argv, t_data *data)
{
	if (argc == 5 || argc == 6)
	{
		if (argc == 5)
			return (check_params(argv, data, 0));
		else
			return (check_params(argv, data, 1));
	}
	else
		return (write(2, "Philo : wrong number of arguments\n", 34), 1);
}

void	mutex_destroy(t_data *data, pthread_mutex_t *forks)
{
	int	i;

	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->meal_lock);
	pthread_mutex_destroy(&data->dead_lock);
	i = 0;
	while (i < data->philos[0].num_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*(philo)->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	ft_think(t_philo *philo)
{
	size_t	time;

	time = get_time() - philo->start_time;
	pthread_mutex_lock(philo->write_lock);
	if (!is_dead(philo))
		printf("%zu %d is thinking\n", time, philo->id);
	pthread_mutex_unlock(philo->write_lock);
}

void	ft_sleep(t_philo *philo)
{
	size_t	time;

	time = get_time() - philo->start_time;
	pthread_mutex_lock(philo->write_lock);
	if (!is_dead(philo))
		printf("%zu %d is sleeping\n", time, philo->id);
	pthread_mutex_unlock(philo->write_lock);
	ft_usleep(philo->time_to_sleep);
}

void	ft_eat(t_philo *philo)
{
	size_t	time;

	time = get_time() - philo->start_time;
	pthread_mutex_lock(philo->write_lock);
	if (!is_dead(philo))
		printf("%zu %d has taken a fork\n", time, philo->id);
	pthread_mutex_unlock(philo->write_lock);
	pthread_mutex_lock(philo->l_fork);
	time = get_time() - philo->start_time;
	pthread_mutex_lock(philo->write_lock);
	if (!is_dead(philo))
		printf("%zu %d has taken a fork\n", time, philo->id);
	pthread_mutex_unlock(philo->write_lock);
	philo->eating = 1;
	time = get_time() - philo->start_time;
	pthread_mutex_lock(philo->write_lock);
	if (!is_dead(philo))
		printf("%zu %d is eating\n", time, philo->id);
	pthread_mutex_unlock(philo->write_lock);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}


void	*routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!is_dead(philo))
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (pointer);
}

int	exec_thread(t_data *data, pthread_mutex_t *forks)
{
	int			i;

	i = 0;
	while (i < data->philos[0].num_of_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &routine,
				&data->philos[i]) != 0)
			return (mutex_destroy(data, forks), 1);
		i++;
	}
	i = 0;
	while (i < data->philos[0].num_of_philos)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			return (mutex_destroy(data, forks), 1);
		i++;
	}
	return (0);
}

void	make_philos(t_data *data, pthread_mutex_t *forks, int i)
{
	while (++i < data->args[0])
	{
		data->philos[i].id = i + 1;
		data->philos[i].eating = 0;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal = get_time();
		data->philos->time_to_die = data->args[1];
		data->philos->time_to_eat = data->args[2];
		data->philos->time_to_sleep = data->args[3];
		data->philos[i].start_time = get_time();
		data->philos->num_of_philos = data->args[0];
		if (data->args[5] == 0)
			data->philos->num_times_to_eat = data->args[5];
		else
			data->philos->num_times_to_eat = -1;
		data->philos[i].dead = &data->dead_flag;
		if (i == 0)
			data->philos[i].r_fork = &forks[data->philos[i].num_of_philos - 1];
		else
			data->philos[i].r_fork = &forks[i - 1];
		data->philos[i].l_fork = &forks[i];
		data->philos[i].write_lock = &data->write_lock;
		data->philos[i].meal_lock = &data->meal_lock;
		data->philos[i].dead_lock = &data->dead_lock;
	}
}

int	init_structs(t_data *data, pthread_mutex_t *forks)
{
	int	i;

	data->dead_flag = 0;
	pthread_mutex_init(&data->write_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	pthread_mutex_init(&data->dead_lock, NULL);
	i = 0;
	while (i < data->args[0])
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	i = -1;
	make_philos(data, forks, i);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data			data;
	t_philo			philos[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];

	data.philos = philos;
	if (init_params(argc, argv, &data) == 1)
		return (1);
	init_structs(&data, forks);
	if (exec_thread(&data, forks) == 1)
		return (1);
	return (0);
}
