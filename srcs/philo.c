/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:35:43 by omajdoub          #+#    #+#             */
/*   Updated: 2023/07/16 19:35:44 by omajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	check_philo_death(t_philo *philo)
{
	if ((int)(get_timestamp() - philo->last_ate) > philo->data->time2die)
	{
		pthread_mutex_lock(philo->data->print_mutex);
		printf("%i has died\n", philo->phid);
		return (1);
	}
	return (0);
}

void	monitor_philos(t_data *data)
{
	int		num_philos_ate;
	int		i;
	t_philo	*philo;

	num_philos_ate = 0;
	while (1)
	{
		i = 0;
		while (i < data->philo_num)
		{
			philo = data->philos[i];
			if (philo->eat_count == philo->data->max_eat_count)
				num_philos_ate++;
			else
				num_philos_ate = 0;
			if (check_philo_death(philo))
				return ;
			i++;
		}
		if (num_philos_ate == data->philo_num)
			return ;
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 5 || argc == 6)
	{
		if ((isvalid(argv)) == 1)
		{
			errorf();
			return (0);
		}
		data = initial_data(argv, argc);
		if (!data)
			return (1);
		init_philos(data);
		monitor_philos(data);
	}
	else
		errorf();
	return (0);
}
