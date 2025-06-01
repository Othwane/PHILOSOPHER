/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unky0 <unky0@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:35:51 by omajdoub          #+#    #+#             */
/*   Updated: 2025/06/01 17:14:35 by unky0            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void monitor(t_data *data)
{
	int i;
	while (!data->stop)
	{
		i = -1;
		int finished = 0;
		while (++i < data->philo_num)
		{
			pthread_mutex_lock(&data->philos[i].meal_lock);
            if ((int)(get_time() - data->philos[i].last_ate) > data->time_to_die)
            {
                pthread_mutex_lock(&data->data_lock);
                data->stop = 1;
                pthread_mutex_unlock(&data->data_lock);
                print_state(&data->philos[i], "died");
                pthread_mutex_unlock(&data->philos[i].meal_lock);
                return;
            }
            if (data->max_eat > 0 && data->philos[i].eat_count >= data->max_eat)
                finished++;
            pthread_mutex_unlock(&data->philos[i].meal_lock);

		}
		if (data->max_eat > 0 && finished == data->philo_num)
		{
			pthread_mutex_lock(&data->data_lock);
			data->stop = 1;
			pthread_mutex_unlock(&data->data_lock);
			return;
		}
		usleep(1000);
	}
}
