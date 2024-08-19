/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:11:20 by jmakkone          #+#    #+#             */
/*   Updated: 2024/08/14 22:33:58 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		exit_failure("Error: data malloc failed.");
	validate_input(ac, av, data);
	init_data(data);
	start_routine(data);
	return (EXIT_SUCCESS);
}
