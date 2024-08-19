/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:51:49 by jmakkone          #+#    #+#             */
/*   Updated: 2024/08/17 21:25:26 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_semaphores(t_data *data)
{
	if (data->forks)
	{
		sem_close(data->forks);
		sem_unlink("forks");
	}
	if (data->philo_lock)
	{
		sem_close(data->philo_lock);
		sem_unlink("philo_lock");
	}
	if (data->stop)
	{
		sem_close(data->stop);
		sem_unlink("stop");
	}
}

void	clean_allocations(t_data *data)
{
	free_semaphores(data);
	free(data->philos);
	free(data);
}

void	exit_failure(char *str)
{
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}
