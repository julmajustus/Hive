/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:00:29 by jmakkone          #+#    #+#             */
/*   Updated: 2024/08/18 00:59:50 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	clean_routine(pthread_t monitor_thread, t_data *data, int stage)
{
	int		i;

	i = 0;
	if (stage > 1)
	{
		if (stage >= 2)
			pthread_join(monitor_thread, NULL);
		while (i < data->philo_count)
		{
			pthread_join(data->philos[i].thread_id, NULL);
			i++;
		}
	}
	i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->philo_lock);
	clean_allocations(data);
	if (stage < 3)
		exit_failure("Thread creation failed.");
}

void	start_routine(t_data *data)
{
	pthread_t	monitor_thread;
	int			i;

	monitor_thread = 0;
	i = 0;
	data->start_time = get_time();
	while (i < data->philo_count)
	{
		data->philos[i].last_meal = get_time();
		if (pthread_create(&data->philos[i].thread_id, NULL, \
					&routine, &data->philos[i]) != 0)
			clean_routine(monitor_thread, data, 1);
		i++;
	}
	if (pthread_create(&monitor_thread, NULL, &monitor, data) != 0)
		clean_routine(monitor_thread, data, 2);
	clean_routine(monitor_thread, data, 3);
}
