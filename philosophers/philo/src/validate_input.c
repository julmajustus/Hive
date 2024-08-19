/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:26:28 by jmakkone          #+#    #+#             */
/*   Updated: 2024/08/14 21:52:59 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	how_to(t_data *data)
{
	printf("Usage: ./philo 'Number of philosophers' 'time_to_die'");
	printf(" 'time_to_eat' 'time_to_sleep' ");
	printf("(optional) 'times_to_eat'\n");
	printf("Arguments:\n");
	printf(" Number of philosophers : The number of philosophers and forks.\n");
	printf(" time_to_die            : Maximum time (in milliseconds)");
	printf(" a philosopher can live without eating.\n");
	printf(" time_to_eat            : Time (in milliseconds)");
	printf(" it takes for a philosopher to eat.\n");
	printf(" time_to_sleep          : Time (in milliseconds)");
	printf(" a philosopher sleeps after eating.\n");
	printf(" (optional) times_to_eat: Number of times");
	printf(" each philosopher must eat before the simulation ends.\n");
	free(data);
	exit(EXIT_FAILURE);
}

static int	ft_atoi(char *str, t_data *data)
{
	long	sum;

	sum = 0;
	while (*str && *str >= '0' && *str <= '9')
		sum = sum * 10 + *str++ - '0';
	if (*str || sum > INT_MAX || sum < INT_MIN)
	{
		printf("Error: Input should be positive int value.\n");
		how_to(data);
	}
	return ((int)sum);
}

static void	check_args(t_data *data)
{
	if (!(data->philo_count > 0 && data->philo_count <= 200))
	{
		printf("Error: Number of philosophers should be 1-200.\n");
		how_to(data);
	}
}

void	validate_input(int ac, char **av, t_data *data)
{
	if (ac < 5 || ac > 6)
		how_to(data);
	data->philo_count = ft_atoi(av[1], data);
	data->time_to_die = ft_atoi(av[2], data);
	data->time_to_eat = ft_atoi(av[3], data);
	data->time_to_sleep = ft_atoi(av[4], data);
	if (ac == 6)
		data->meals_to_eat = ft_atoi(av[5], data);
	else
		data->meals_to_eat = -1;
	check_args(data);
}
