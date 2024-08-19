/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_routine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:00:29 by jmakkone          #+#    #+#             */
/*   Updated: 2024/08/17 22:53:18 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	start_routine(t_data *data)
{
	int	i;
	int	pid;

	i = 0;
	data->start_time = get_time();
	while (i < data->philo_count)
	{
		data->philos[i].last_meal = get_time();
		pid = fork();
		if (pid < 0)
		{
			kill_philos(data, 15);
			clean_allocations(data);
			exit_failure("Forking failed.");
		}
		else if (pid == 0)
			routine(&data->philos[i]);
		else
			data->philos[i].pid = pid;
		i++;
	}
	monitor(data);
	clean_allocations(data);
}
