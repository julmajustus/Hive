/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:19:13 by jmakkone          #+#    #+#             */
/*   Updated: 2024/08/19 16:29:26 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	check_eat_count(t_data *data, t_philo *philo)
{
	sem_wait(data->philo_lock);
	if (data->meals_to_eat != -1 && philo->meal_count >= data->meals_to_eat)
	{
		data->kill = 1;
		sem_post(data->philo_lock);
		usleep(600000);
		sem_post(data->stop);
		usleep(10000);
		join_threads(data, philo);
		clean_allocations(data);
		exit(EXIT_SUCCESS);
	}
	sem_post(data->philo_lock);
}

static void	philo_takes_forks(t_data *data, t_philo *philo)
{
	usleep(100);
	sem_wait(data->forks);
	print_msg(data, philo->id, "has taken a fork");
	usleep(100);
	sem_wait(data->forks);
	print_msg(data, philo->id, "has taken a fork");
}

static void	philo_eats(t_data *data, t_philo *philo)
{
	sem_wait(data->philo_lock);
	philo->last_meal = get_time();
	philo->meal_count++;
	sem_post(data->philo_lock);
	print_msg(data, philo->id, "is eating");
	ft_sleep(data, data->time_to_eat);
	sem_post(data->forks);
	sem_post(data->forks);
}

void	routine(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	create_threads(data, philo);
	if (philo->data->philo_count == 1)
	{
		sem_wait(data->forks);
		print_msg(data, philo->id, "has taken a fork");
		ft_sleep(data, data->time_to_die + 10);
	}
	if (philo->id % 2 == 0)
		usleep(500);
	while (!kill_switch(data))
	{
		check_eat_count(data, philo);
		philo_takes_forks(data, philo);
		philo_eats(data, philo);
		print_msg(data, philo->id, "is sleeping");
		ft_sleep(data, data->time_to_sleep);
		print_msg(data, philo->id, "is thinking");
	}
	join_threads(data, philo);
	clean_allocations(data);
	exit(EXIT_FAILURE);
}
