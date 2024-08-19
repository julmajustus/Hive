/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:51:49 by jmakkone          #+#    #+#             */
/*   Updated: 2024/08/17 23:08:21 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_failure(char *str)
{
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}

void	clean_allocations(t_data *data)
{
	free(data->philos);
	free(data->forks);
	free(data);
}
