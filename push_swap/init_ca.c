/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ca.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 08:13:37 by jmakkone          #+#    #+#             */
/*   Updated: 2024/07/02 10:26:29 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ca_push(t_circular_array *ca, int value)
{
	if (ca->length < ca->size)
	{
		ca->array[ca->tail] = value;
		ca->tail = (ca->tail + 1) % ca->size;
		ca->length++;
	}
}

int	ca_pop(t_circular_array *ca)
{
	int	value;

	if (ca->length > 0)
	{
		value = ca->array[ca->head];
		ca->head = (ca->head + 1) % ca->size;
		ca->length--;
		return (value);
	}
	return (0);
}

int	fill_ca(int argc, char **argv, t_circular_array *ca_a)
{
	long		n;
	int			i;

	n = 0;
	if (is_number(argv[0]))
		i = 0;
	else
		i = 1;
	while (i < argc)
	{
		n = ft_push_swap_atoi(argv[i]);
		if (n == LONG_MAX)
			return (0);
		ca_push(ca_a, n);
		i++;
	}
	return (1);
}

static void	init_ca_variables(t_circular_array *ca, int size)
{
	ca->size = size;
	ca->head = 0;
	ca->tail = 0;
	ca->length = 0;
	ca->cheapest = 0;
	ca->combined_cost = 0;
}

t_circular_array	*create_circular_array(int size)
{
	t_circular_array	*ca;

	ca = malloc(sizeof(t_circular_array));
	if (!ca)
		return (NULL);
	ca->array = malloc(size * sizeof(int));
	if (!ca->array)
	{
		free(ca);
		return (NULL);
	}
	ca->cost_a = (int *)malloc(size * sizeof(int));
	ca->cost_b = (int *)malloc(size * sizeof(int));
	ca->target_positions = (int *)malloc(size * sizeof(int));
	ca->preferred_pos = (int *)malloc(size * sizeof(int));
	if (!ca->cost_a || !ca->cost_b || !ca->target_positions \
										|| !ca->preferred_pos)
	{
		free_circular_array(ca);
		return (NULL);
	}
	init_ca_variables(ca, size);
	return (ca);
}
