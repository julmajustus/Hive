/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:46:59 by jmakkone          #+#    #+#             */
/*   Updated: 2024/08/17 23:45:27 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	kill_switch(t_data *data)
{
	int	stop;

	pthread_mutex_lock(&data->philo_lock);
	stop = data->kill;
	pthread_mutex_unlock(&data->philo_lock);
	return (stop);
}

static t_philo	*check_condition(t_data *data)
{
	size_t	time;
	int		i;

	i = 0;
	while (i < data->philo_count)
	{
		time = get_time();
		pthread_mutex_lock(&data->philo_lock);
		if (time - data->philos[i].last_meal > (size_t)data->time_to_die)
		{
			pthread_mutex_unlock(&data->philo_lock);
			print_msg(data, data->philos[i], "has died");
			pthread_mutex_lock(&data->philo_lock);
			data->kill = 1;
			pthread_mutex_unlock(&data->philo_lock);
			return (&data->philos[i]);
		}
		pthread_mutex_unlock(&data->philo_lock);
		i++;
	}
	return (NULL);
}

void	*monitor(void *ptr)
{
	t_data	*data;
	t_philo	*philo;

	data = (t_data *)ptr;
	while (1)
	{
		philo = check_condition(data);
		if (philo)
			return (NULL);
		pthread_mutex_lock(&data->philo_lock);
		if (data->full_count >= data->philo_count)
		{
			data->kill = 1;
			pthread_mutex_unlock(&data->philo_lock);
			break ;
		}
		pthread_mutex_unlock(&data->philo_lock);
		usleep(100);
	}
	return (NULL);
}
