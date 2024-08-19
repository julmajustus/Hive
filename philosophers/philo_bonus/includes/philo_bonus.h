/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:48:56 by jmakkone          #+#    #+#             */
/*   Updated: 2024/08/19 16:21:37 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>
# include <semaphore.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_philo
{
	int				id;
	int				meal_count;
	size_t			last_meal;
	pthread_t		death_check;
	pthread_t		stop_check;
	pid_t			pid;
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
	t_philo			*philos;
	sem_t			*forks;
	sem_t			*philo_lock;
	sem_t			*stop;
}	t_data;

void	validate_input(int ac, char **av, t_data *data);
void	exit_failure(char *str);
void	free_semaphores(t_data *data);
void	clean_allocations(t_data *data);
void	init_data(t_data *data);
size_t	get_time(void);
void	print_msg(t_data *data, int philo_id, char *msg);
void	print_death(t_data *data, int philo_id);
void	ft_sleep(t_data *data, size_t time);
void	start_routine(t_data *data);
void	routine(t_philo *philo);
void	create_threads(t_data *data, t_philo *philo);
void	join_threads(t_data *data, t_philo *philo);
void	monitor(t_data *data);
void	*check_death_condition(void *ptr);
void	*check_stop_condition(void *ptr);
int		kill_switch(t_data *data);
void	kill_philos(t_data *data, int signal);

#endif
