/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routines_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:08:31 by jmakkone          #+#    #+#             */
/*   Updated: 2024/08/19 09:43:03 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	kill_switch(t_data *data)
{
	int	kill;

	sem_wait(data->philo_lock);
	kill = data->kill;
	sem_post(data->philo_lock);
	return (kill);
}

static void	stop_condition_met(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		sem_post(data->stop);
		i++;
	}
}

void	*check_death_condition(void *ptr)
{
	t_philo	*philo;
	size_t	time;

	philo = (t_philo *)ptr;
	while (1)
	{
		sem_wait(philo->data->philo_lock);
		if (philo->data->kill)
		{
			sem_post(philo->data->philo_lock);
			break ;
		}
		time = get_time();
		if (time - philo->last_meal > (size_t)philo->data->time_to_die)
		{
			philo->data->kill = 1;
			print_death(philo->data, philo->id);
			stop_condition_met(philo->data);
			sem_post(philo->data->philo_lock);
			break ;
		}
		sem_post(philo->data->philo_lock);
		usleep(100);
	}
	return (NULL);
}

void	*check_stop_condition(void *ptr)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)ptr;
	data = philo->data;
	sem_wait(data->stop);
	sem_wait(data->philo_lock);
	data->kill = 1;
	sem_post(data->philo_lock);
	return (NULL);
}
