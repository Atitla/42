/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:18:01 by ecunha            #+#    #+#             */
/*   Updated: 2024/02/04 13:41:19 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		(void) write(2, "gettimeofday() error\n", 22);
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
	while (i <= (3 + flag))
	{
		data->args[i] = ft_atoi(argv[i + 1]);
		if (data->args[i] <= 0)
		{
			return ((void)write(2, "Philo : Wrong number in argument ", 34), \
				printf("%i\n", (i + 1)), 1);
		}
		i++;
	}
	if (data->args[0] > PHILO_MAX)
		return ((void)write(2, "Philo : Too many philosophers\n", 30), 1);
	if (flag == 0)
		data->args[4] = -1;
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
		return ((void)write(2, "Philo : wrong number of arguments\n", 34), 1);
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

int	is_phi_dead(t_phi *phi)
{
	pthread_mutex_lock(phi->meal_lock);
	if (get_time() - phi->last_meal >= phi->time_to_die
		&& phi->eating == 0)
		return (pthread_mutex_unlock(phi->meal_lock), 1);
	pthread_mutex_unlock(phi->meal_lock);
	return (0);
}

int	 is_dead(t_phi *phi)
{
	pthread_mutex_lock(phi->dead_lock);
	if (*(phi)->dead == 1)
		return (pthread_mutex_unlock(phi->dead_lock), 1);
	pthread_mutex_unlock(phi->dead_lock);
	return (0);
}

int	monitor_if_phi_dead(t_phi *phi)
{
	size_t	time;
	int		i;

	i = 0;
	while (i < phi[0].num_of_philos)
	{
		if (is_phi_dead(&phi[i]) == 1)
		{
			time = get_time() - phi->start_time;
			pthread_mutex_lock(phi->write_lock);
			printf("%zu %d died\n", time, phi->id);
			pthread_mutex_unlock(phi->write_lock);
			pthread_mutex_lock(phi[0].dead_lock);
			*(phi->dead) = 1;
			pthread_mutex_unlock(phi[0].dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

int	monitor_num_tte(t_phi *phi)
{
	int	i;
	int	phi_finished;

	phi_finished = 0;
	if (phi[0].num_times_to_eat == -1)
		return (0);
	i = 0;
	while (i < phi[0].num_of_philos)
	{
		pthread_mutex_lock(phi[i].meal_lock);
		if (phi[i].meals_eaten >= phi[i].num_times_to_eat)
			phi_finished++;
		pthread_mutex_unlock(phi[i].meal_lock);
		i++;
	}
	if (phi_finished == phi[0].num_of_philos)
	{
		pthread_mutex_lock(phi[0].dead_lock);
		*phi->dead = 1;
		pthread_mutex_unlock(phi[0].dead_lock);
		return (1);
	}
	return (0);
}

void	ft_think(t_phi *phi)
{
	size_t	time;

	time = get_time() - phi->start_time;
	pthread_mutex_lock(phi->write_lock);
	if (!is_dead(phi))
		printf("%zu %d is thinking\n", time, phi->id);
	pthread_mutex_unlock(phi->write_lock);
}

void	ft_sleep(t_phi *phi)
{
	size_t	time;

	time = get_time() - phi->start_time;
	pthread_mutex_lock(phi->write_lock);
	if (!is_dead(phi))
		printf("%zu %d is sleeping\n", time, phi->id);
	pthread_mutex_unlock(phi->write_lock);
	ft_usleep(phi->time_to_sleep);
}

void	ft_eat(t_phi *phi, size_t time)
{
	time = get_time() - phi->start_time;
	pthread_mutex_lock(phi->write_lock);
	if (!is_dead(phi))
		printf("%zu %d has taken a fork\n", time, phi->id);
	pthread_mutex_unlock(phi->write_lock);
	pthread_mutex_lock(phi->l_fork);
	phi->eating = 1;
	time = get_time() - phi->start_time;
	pthread_mutex_lock(phi->write_lock);
	if (!is_dead(phi))
		printf("%zu %d has taken a fork\n", time, phi->id);
	pthread_mutex_unlock(phi->write_lock);
	time = get_time() - phi->start_time;
	pthread_mutex_lock(phi->write_lock);
	if (!is_dead(phi))
		printf("%zu %d is eating\n", time, phi->id);
	pthread_mutex_unlock(phi->write_lock);
	pthread_mutex_lock(phi->meal_lock);
	phi->meals_eaten++;
	phi->last_meal = get_time();
	pthread_mutex_unlock(phi->meal_lock);
	ft_usleep(phi->time_to_eat);
	phi->eating = 0;
	pthread_mutex_unlock(phi->l_fork);
	pthread_mutex_unlock(phi->r_fork);
}

void	*routine(void *pointer)
{
	t_phi	*phi;
	size_t	time;

	phi = (t_phi *)pointer;
	time = 0;
	//while (*(phi->bool_start) == 0)
	//	ft_usleep(1);
	if (phi->id % 2 == 0)
		ft_sleep(phi);
	while (!is_dead(phi))
	{
	//	if (phi->meals_eaten == 0 && phi->id % 2 == 0)
	//		ft_sleep(phi);
		ft_eat(phi, time);
		ft_sleep(phi);
		ft_think(phi);
	}
	return (pointer);
}

void	*monitor_routine(void *pointer)
{
	t_phi	*phi;

	phi = (t_phi *)pointer;
	while (1)
		if (monitor_if_phi_dead(phi) == 1 || monitor_num_tte(phi) == 1)
			break ;
	return (pointer);
}

int	exec_thread(t_data *data, pthread_mutex_t *forks)
{
	int			i;
	pthread_t	monitor;

	if (pthread_create(&monitor, NULL, &monitor_routine, \
			data->philos) != 0)
		return (1);
	i = 0;
	while (i < data->philos[0].num_of_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &routine, \
				&data->philos[i]) != 0)
			return (mutex_destroy(data, forks), 1);
		i++;
	}
	// data->bool_start = 1;
	if (pthread_join(monitor, NULL) != 0)
		return (mutex_destroy(data, forks), 1);
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
		data->philos[i].time_to_die = data->args[1];
		data->philos[i].time_to_eat = data->args[2];
		data->philos[i].time_to_sleep = data->args[3];
		data->philos[i].start_time = get_time();
		data->philos[i].num_of_philos = data->args[0];
		if (data->args[4] > 0)
			data->philos[i].num_times_to_eat = data->args[4];
		else
			data->philos[i].num_times_to_eat = -1;
		data->philos[i].dead = &data->dead_flag;
		if (i == 1)
			data->philos[i].r_fork = &forks[data->philos[i].num_of_philos - 1];
		else
			data->philos[i].r_fork = &forks[i - 1];
		data->philos[i].l_fork = &forks[i];
		data->philos[i].write_lock = &data->write_lock;
		data->philos[i].meal_lock = &data->meal_lock;
		data->philos[i].dead_lock = &data->dead_lock;
	}
}

// void	pointer_start_philos(t_data *data, int i)
// {
// 	while (++i < data->args[0])
// 		data->philos[i].bool_start = &data->bool_start;
// }

int	init_structs(t_data *data, pthread_mutex_t *forks)
{
	int	i;

	data->dead_flag = 0;
	//data->bool_start = 0;
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
	// pointer_start_philos(data, i);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data			data;
	t_phi			philos[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];

	data.philos = philos;
	if (init_params(argc, argv, &data) == 1)
		return (1);
	init_structs(&data, forks);
	if (exec_thread(&data, forks) == 1)
		return (1);
	mutex_destroy(&data, forks);
	return (0);
}
