/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:36:02 by omajdoub          #+#    #+#             */
/*   Updated: 2023/07/16 19:36:02 by omajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

unsigned long long	get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
}

void	print_state(t_philo *philo, t_states state)
{
	pthread_mutex_lock(philo->data->print_mutex);
	if (state == ForkTaken)
		printf("%llu %i has taken a fork\n", get_timestamp()
			- philo->data->start_time, philo->phid);
	if (state == Eating)
		printf("%llu %i is eating\n", get_timestamp() - philo->data->start_time,
			philo->phid);
	if (state == Sleeping)
		printf("%llu %i is sleeping\n", get_timestamp()
			- philo->data->start_time, philo->phid);
	if (state == Thinking)
		printf("%llu %i is thinking\n", get_timestamp()
			- philo->data->start_time, philo->phid);
	pthread_mutex_unlock(philo->data->print_mutex);
}

void	ssleep(unsigned int time)
{
	unsigned long long	start;
	unsigned long long	diff;

	start = get_timestamp();
	while (1)
	{
		diff = get_timestamp() - start;
		if (diff >= time)
			break ;
		usleep(50);
	}
}

int	ft_atoi(char *s)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	sign = 1;
	result = 0;
	while ((s[i] != '\0') && ((s[i] >= 9 && s[i] <= 13) || s[i] == 32))
		i++;
	if (s[i] == 45 || s[i] == 43)
	{
		if (s[i] == 45)
			sign = -1;
		i++;
	}
	while (s[i] >= 48 && s[i] <= 57)
	{
		result *= 10;
		result += (s[i] - 48);
		i++;
	}
	return (result * sign);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
