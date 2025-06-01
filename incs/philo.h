/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unky0 <unky0@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:35:56 by omajdoub          #+#    #+#             */
/*   Updated: 2025/06/01 17:10:10 by unky0            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
#include <string.h>

struct s_data;

typedef struct s_philo
{
	int					id;
	int					eat_count;
	long long			last_ate;
	pthread_t			thread_id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data		*data;
	pthread_mutex_t	meal_lock;
}t_philo;

typedef struct s_data
{
	int					philo_num;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					max_eat;
	int					all_ate;
	int					stop;
	long long			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	data_lock;
	t_philo				*philos;
}t_data;

int					is_valid_args(int argc, char **argv);
t_data				*init_data(int argc, char **argv);
int					init_philos(t_data *data);
long long			get_time(void);
long long			timestamp(t_data *data);
void				ms_sleep(int ms);
void				print_state(t_philo *philo, char *msg);
void				*philo_routine(void *ptr);
void				monitor(t_data *data);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
void				error_exit(char *msg);
void				free_all(t_data *data);

#endif