/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:07:44 by jmakkone          #+#    #+#             */
/*   Updated: 2024/08/14 22:07:34 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

size_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print_msg(t_data *data, int philo_id, char *msg)
{
	if (!kill_switch(data))
	{
		sem_wait(data->philo_lock);
		printf("%ld %d %s\n", get_time() - data->start_time, philo_id, msg);
		sem_post(data->philo_lock);
	}
}

void	print_death(t_data *data, int philo_id)
{
	size_t	time;

	if (data->kill == 1)
	{
		time = get_time() - data->start_time;
		printf("%ld %d %s\n", time, philo_id, "has died");
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
