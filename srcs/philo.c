/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unky0 <unky0@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:35:43 by omajdoub          #+#    #+#             */
/*   Updated: 2025/06/01 16:38:21 by unky0            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int main(int argc, char **argv)
{
	t_data *data;

	if (!is_valid_args(argc, argv))
		error_exit("Invalid arguments\n");
	data = init_data(argc, argv);
	if (!data || !init_philos(data))
		return (1);
	monitor(data);
	free_all(data);
	return (0);
}