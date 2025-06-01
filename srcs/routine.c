/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unky0 <unky0@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:35:54 by omajdoub          #+#    #+#             */
/*   Updated: 2025/06/01 17:06:00 by unky0            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void eat(t_philo *p)
{
	pthread_mutex_lock(p->left_fork);
	print_state(p, "has taken a fork");
	if (p->data->philo_num == 1)
	{
		ms_sleep(p->data->time_to_die);
		pthread_mutex_unlock(p->left_fork);
		return ;
	}
	pthread_mutex_lock(p->right_fork);
	print_state(p, "has taken a fork");
	print_state(p, "is eating");
	pthread_mutex_lock(&p->meal_lock);
	p->last_ate = get_time();
	p->eat_count++;
	pthread_mutex_unlock(&p->meal_lock);
	ms_sleep(p->data->time_to_eat);
	pthread_mutex_unlock(p->left_fork);
	pthread_mutex_unlock(p->right_fork);
}

void *philo_routine(void *ptr)
{
	t_philo *p = (t_philo *)ptr;
	if (p->id % 2)
		usleep(1000);
	while (1)
	{
		pthread_mutex_lock(&p->data->data_lock);
		if (p->data->stop)
		{
			pthread_mutex_unlock(&p->data->data_lock);
			break;
		}
		pthread_mutex_unlock(&p->data->data_lock);
		eat(p);
		pthread_mutex_lock(&p->data->data_lock);
		if (p->data->stop)
		{
			pthread_mutex_unlock(&p->data->data_lock);
			break;
		}
		pthread_mutex_unlock(&p->data->data_lock);
		print_state(p, "is sleeping");
		ms_sleep(p->data->time_to_sleep);
		print_state(p, "is thinking");
	}
	return (NULL);
}