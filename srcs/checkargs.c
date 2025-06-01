/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unky0 <unky0@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:35:48 by omajdoub          #+#    #+#             */
/*   Updated: 2025/06/01 16:41:54 by unky0            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int ft_atoi(const char *str)
{
	int res = 0;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + (*str++ - '0');
	return (res);
}

int is_valid_args(int argc, char **argv)
{
	int i = 1, j;
	if (argc != 5 && argc != 6)
		return (0);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			if (!ft_isdigit(argv[i][j++]))
				return (0);
		if (ft_atoi(argv[i]) <= 0)
			return (0);
		i++;
	}
	return (1);
}

void error_exit(char *msg)
{
	write(2, msg, strlen(msg));
	exit(1);
}