/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unky0 <unky0@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:36:02 by omajdoub          #+#    #+#             */
/*   Updated: 2025/06/01 17:07:24 by unky0            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

long long get_time(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long long timestamp(t_data *data)
{
	return (get_time() - data->start_time);
}

void ms_sleep(int ms)
{
	long long start = get_time();
	while (get_time() - start < ms)
		usleep(100);
}

void print_state(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->data_lock);
	int stopped = philo->data->stop;
	pthread_mutex_unlock(&philo->data->data_lock);
	if (!stopped)
	{
		pthread_mutex_lock(&philo->data->print);
		printf("%lld %d %s\n", timestamp(philo->data), philo->id, msg);
		pthread_mutex_unlock(&philo->data->print);
	}
}

void free_all(t_data *data)
{
	int i;
	for (i = 0; i < data->philo_num; i++)
		pthread_join(data->philos[i].thread_id, NULL);
	free(data->philos);
	free(data->forks);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->data_lock);
	free(data);
}
