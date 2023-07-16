/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:35:48 by omajdoub          #+#    #+#             */
/*   Updated: 2023/07/16 19:35:49 by omajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	isvalid(char **argv)
{
	int	i;
	int	ii;

	i = 0;
	while (argv[++i])
	{
		ii = 0;
		while (argv[i][ii])
		{
			if (!ft_isdigit(argv[i][ii]))
				return (1);
			ii++;
		}
		if (ft_atoi(argv[i]) <= 0)
			return (1);
	}
	return (0);
}

t_data	*initial_data(char **argv, int argc)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
	{
		errorf();
		return (NULL);
	}
	data->philo_num = ft_atoi(argv[1]);
	data->time2die = ft_atoi(argv[2]);
	data->time2eat = ft_atoi(argv[3]);
	data->time2sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->max_eat_count = ft_atoi(argv[5]);
	else
		data->max_eat_count = -1;
	return (data);
}

void	errorf(void)
{
	printf("Error\n");
}
