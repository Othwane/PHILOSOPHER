/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unky0 <unky0@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:35:51 by omajdoub          #+#    #+#             */
/*   Updated: 2025/06/01 16:43:52 by unky0            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

static int init_mutexes(t_data *data)
{
	int i;
	if (pthread_mutex_init(&data->print, NULL))
		return (0);
	if (pthread_mutex_init(&data->data_lock, NULL))
		return (0);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_num);
	if (!data->forks)
		return (0);
	for (i = 0; i < data->philo_num; i++)
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (0);
	return (1);
}

t_data *init_data(int argc, char **argv)
{
	t_data *data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->philo_num = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->max_eat = (argc == 6) ? ft_atoi(argv[5]) : -1;
	data->all_ate = 0;
	data->stop = 0;
	data->start_time = get_time();
	if (!init_mutexes(data))
		return (NULL);
	return (data);
}

int init_philos(t_data *data)
{
	int i;

data->philos = malloc(sizeof(t_philo) * data->philo_num);
	if (!data->philos)
		return (0);
	for (i = 0; i < data->philo_num; i++)
	{
		data->philos[i].id = i + 1;
		data->philos[i].eat_count = 0;
		data->philos[i].last_ate = data->start_time;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->philo_num];
		data->philos[i].data = data;
		pthread_create(&data->philos[i].thread_id, NULL, philo_routine, &data->philos[i]);
	}
	return (1);
}

