/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:15:33 by jmakkone          #+#    #+#             */
/*   Updated: 2024/08/17 21:27:17 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	init_philos(t_data *data)
{
	int		i;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * data->philo_count);
	if (!data->philos)
	{
		free_semaphores(data);
		free(data);
		exit_failure("Error: philos malloc failed.");
	}
	while (i < data->philo_count)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meal_count = 0;
		data->philos[i].last_meal = get_time();
		data->philos[i].data = data;
		i++;
	}
}

static void	init_semaphores(t_data *data)
{
	sem_unlink("forks");
	sem_unlink("philo_lock");
	sem_unlink("stop");
	data->forks = sem_open("forks", O_CREAT, 0644, data->philo_count);
	data->philo_lock = sem_open("philo_lock", O_CREAT, 0644, 1);
	data->stop = sem_open("stop", O_CREAT, 0644, 0);
	if (data->forks == SEM_FAILED || \
		data->philo_lock == SEM_FAILED || \
		data->stop == SEM_FAILED)
	{
		free(data);
		exit_failure("Error: sem_open failed.");
	}
}

void	init_data(t_data *data)
{
	init_semaphores(data);
	init_philos(data);
	data->kill = 0;
}
