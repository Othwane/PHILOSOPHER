/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:35:56 by omajdoub          #+#    #+#             */
/*   Updated: 2023/07/16 19:41:05 by omajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo	t_philo;

typedef struct s_data
{
	int					philo_num;
	long long			time2eat;
	long long			time2sleep;
	int					time2die;
	int					max_eat_count;
	t_philo				**philos;
	pthread_mutex_t		**forks;
	pthread_mutex_t		*print_mutex;
	unsigned long long	start_time;
}						t_data;

typedef struct s_philo
{
	int					phid;
	pthread_t			thread_id;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	t_data				*data;
	unsigned long long	last_ate;
	int					eat_count;
}						t_philo;

typedef enum e_states
{
	ForkTaken,
	Eating,
	Sleeping,
	Thinking
}						t_states;

t_data					*initial_data(char **argv, int argc);
void					init_philos(t_data *data);
unsigned long long		get_timestamp(void);
void					ssleep(unsigned int time);
void					print_state(t_philo *philo, t_states state);
void					*philo_routine(void *p_philo);
int						isvalid(char **argv);
void					errorf(void);

int						ft_isdigit(int c);
int						ft_atoi(char *s);

#endif
