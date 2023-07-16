#include "../incs/philo.h"

void init_mutexes(t_data* data)
{
	int i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t*) * data->philo_num);
	data->print_mutex = malloc(sizeof(pthread_mutex_t));
	data->datarace_mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(data->print_mutex, NULL);
	pthread_mutex_init(data->datarace_mutex, NULL);
	while (i < data->philo_num)
	{
		data->forks[i] = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(data->forks[i], NULL);
		i++;
	}
}

void init_philos(t_data* data)
{
	int i;

	i = 0;
	data->start_time = get_timestamp();
	data->philos = malloc(sizeof(t_philo*) * data->philo_num);
	init_mutexes(data);
	while (i < data->philo_num)
	{
		data->philos[i] = malloc(sizeof(t_philo));
		data->philos[i]->phid = i + 1;
		data->philos[i]->data = data;
		data->philos[i]->left_fork = data->forks[i];
		data->philos[i]->right_fork = data->forks[(i + 1) % data->philo_num];
		data->philos[i]->last_ate = get_timestamp();
		data->philos[i]->eat_count = 0;
		pthread_create(&data->philos[i]->thread_id, NULL, philo_routine, data->philos[i]);
		usleep(50);
		i++;
	}
}
