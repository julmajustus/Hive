/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:15:33 by jmakkone          #+#    #+#             */
/*   Updated: 2024/08/14 22:19:28 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	if (!data->forks)
	{
		free(data);
		exit_failure("Error: forks malloc failed");
	}
	while (i < data->philo_count)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}

static void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * data->philo_count);
	if (!data->philos)
	{
		while (i < data->philo_count)
			pthread_mutex_destroy(&data->forks[i++]);
		free(data->forks);
		free(data);
		exit_failure("Error: philos malloc failed");
	}
	while (i < data->philo_count)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meal_count = 0;
		data->philos[i].last_meal = get_time();
		data->philos[i].l_fork = &data->forks[i];
		data->philos[i].r_fork = \
				&data->forks[(i + 1) % data->philo_count];
		data->philos[i].data = data;
		i++;
	}
}

void	init_data(t_data *data)
{
	init_forks(data);
	init_philos(data);
	data->kill = 0;
	data->full_count = 0;
	pthread_mutex_init(&data->philo_lock, NULL);
}
