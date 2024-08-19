/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:07:44 by jmakkone          #+#    #+#             */
/*   Updated: 2024/08/08 00:54:27 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print_msg(t_data *data, t_philo philo, char *msg)
{
	size_t	time;

	time = get_time() - data->start_time;
	if (!kill_switch(data))
	{
		pthread_mutex_lock(&data->philo_lock);
		printf("%ld %d %s\n", time, philo.id, msg);
		pthread_mutex_unlock(&data->philo_lock);
	}
}

void	ft_sleep(t_data *data, size_t time)
{
	size_t	start;

	start = get_time();
	if (!kill_switch(data))
	{
		while ((get_time() - start) < time)
			usleep(500);
	}
}
