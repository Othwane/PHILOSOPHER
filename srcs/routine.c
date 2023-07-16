/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:35:54 by omajdoub          #+#    #+#             */
/*   Updated: 2023/07/16 19:35:54 by omajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_state(philo, ForkTaken);
	pthread_mutex_lock(philo->right_fork);
	print_state(philo, ForkTaken);
	print_state(philo, Eating);
	ssleep(philo->data->time2eat);
	philo->last_ate = get_timestamp();
	philo->eat_count++;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	philo_sleep(t_philo *philo)
{
	print_state(philo, Sleeping);
	ssleep(philo->data->time2sleep);
}

void	philo_think(t_philo *philo)
{
	print_state(philo, Thinking);
}

void	*philo_routine(void *p_philo)
{
	t_philo	*philo;

	philo = (t_philo *)p_philo;
	if (philo->phid % 2)
	{
		philo_think(philo);
		ssleep(philo->data->time2eat);
	}
	while (1)
	{
		philo_eat(philo);
		if (philo->eat_count == philo->data->max_eat_count)
			return (NULL);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}
