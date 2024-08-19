/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:19:13 by jmakkone          #+#    #+#             */
/*   Updated: 2024/08/17 23:42:04 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_takes_forks(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->r_fork);
		print_msg(philo->data, *philo, "has taken a fork");
		pthread_mutex_lock(philo->l_fork);
		print_msg(philo->data, *philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		print_msg(philo->data, *philo, "has taken a fork");
		pthread_mutex_lock(philo->r_fork);
		print_msg(philo->data, *philo, "has taken a fork");
	}
}

static void	philo_eats(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->philo_lock);
	if (philo->data->meals_to_eat != -1 && \
		philo->meal_count >= philo->data->meals_to_eat)
		philo->data->full_count++;
	philo->last_meal = get_time();
	philo->meal_count++;
	pthread_mutex_unlock(&philo->data->philo_lock);
	print_msg(philo->data, *philo, "is eating");
	ft_sleep(philo->data, philo->data->time_to_eat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

static void	philo_sleeps(t_philo *philo)
{
	print_msg(philo->data, *philo, "is sleeping");
	ft_sleep(philo->data, philo->data->time_to_sleep);
}

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->data->philo_count == 1)
	{
		pthread_mutex_lock(philo->l_fork);
		print_msg(philo->data, *philo, "has taken a fork");
		pthread_mutex_unlock(philo->l_fork);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		usleep(500);
	while (!kill_switch(philo->data))
	{
		philo_takes_forks(philo);
		philo_eats(philo);
		philo_sleeps(philo);
		print_msg(philo->data, *philo, "is thinking");
	}
	return (NULL);
}
