/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:46:59 by jmakkone          #+#    #+#             */
/*   Updated: 2024/08/17 21:47:24 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_philos(t_data *data, int signal)
{
	int	i;

	i = 0;
	if (signal == 9)
	{
		while (i < data->philo_count)
		{
			if (data->philos[i].pid)
				kill(data->philos[i].pid, SIGKILL);
			i++;
		}
	}
	if (signal == 15)
	{
		while (i < data->philo_count)
		{
			if (data->philos[i].pid)
				kill(data->philos[i].pid, SIGTERM);
			i++;
		}
	}
}

static void	wait_philos_to_exit(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		waitpid(data->philos[i].pid, NULL, 0);
		i++;
	}
}

void	monitor(t_data *data)
{
	int	status;

	while (1)
	{
		waitpid(0, &status, 0);
		sem_wait(data->philo_lock);
		if (WIFEXITED(status) && status > 0)
		{
			kill_philos(data, 9);
			sem_post(data->philo_lock);
			return ;
		}
		if (WIFEXITED(status) && status == 0)
		{
			sem_post(data->philo_lock);
			wait_philos_to_exit(data);
			kill_philos(data, 9);
			return ;
		}
		sem_post(data->philo_lock);
		ft_sleep(data, 1);
	}
}
