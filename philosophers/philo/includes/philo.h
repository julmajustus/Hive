/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:48:56 by jmakkone          #+#    #+#             */
/*   Updated: 2024/08/17 23:08:02 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_philo
{
	int				id;
	int				meal_count;
	size_t			last_meal;
	pthread_t		thread_id;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	struct s_data	*data;

}	t_philo;

typedef struct s_data
{
	int				philo_count;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				meals_to_eat;
	size_t			start_time;
	int				kill;
	int				full_count;
	t_philo			*philos;
	pthread_mutex_t	philo_lock;
	pthread_mutex_t	*forks;
}	t_data;

void	validate_input(int ac, char **av, t_data *data);
void	exit_failure(char *str);
void	clean_allocations(t_data *data);
void	init_data(t_data *data);
size_t	get_time(void);
void	print_msg(t_data *data, t_philo philo, char *msg);
void	ft_sleep(t_data *data, size_t time);
void	start_routine(t_data *data);
void	*routine(void *ptr);
void	*monitor(void *ptr);
int		kill_switch(t_data *data);

#endif
