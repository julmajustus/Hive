/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_handler_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:20:19 by jmakkone          #+#    #+#             */
/*   Updated: 2024/08/19 16:20:41 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	create_threads(t_data *data, t_philo *philo)
{
	if (pthread_create(&philo->death_check, NULL, \
			check_death_condition, philo) != 0)
	{
		clean_allocations(data);
		exit_failure("Thread creation failed.");
	}
	if (pthread_create(&philo->stop_check, NULL, \
			check_stop_condition, philo) != 0)
	{
		clean_allocations(data);
		exit_failure("Thread creation failed.");
	}
}

void	join_threads(t_data *data, t_philo *philo)
{
	if (pthread_join(philo->death_check, NULL) != 0)
	{
		clean_allocations(data);
		exit_failure("Thread join failed.");
	}
	if (pthread_join(philo->stop_check, NULL) != 0)
	{
		clean_allocations(data);
		exit_failure("Thread join failed.");
	}
}
