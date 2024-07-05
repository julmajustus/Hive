/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_target_positions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 08:43:58 by jmakkone          #+#    #+#             */
/*   Updated: 2024/07/02 08:55:49 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_initial_target_position(t_circular_array *ca_a, int b_index)
{
	int		i;
	int		target_pos;
	long	target_idx;
	int		a_index;

	i = 0;
	target_pos = 0;
	target_idx = LONG_MAX;
	while (i < ca_a->length)
	{
		a_index = ca_a->array[(ca_a->head + i) % ca_a->size];
		if (a_index > b_index && a_index < target_idx)
		{
			target_idx = a_index;
			target_pos = i;
		}
		i++;
	}
	if (target_idx == LONG_MAX)
		return (-1);
	return (target_pos);
}

static int	find_minimum_position(t_circular_array *ca_a)
{
	int	i;
	int	target_pos;
	int	target_idx;
	int	a_index;

	i = 0;
	target_pos = 0;
	target_idx = INT_MAX;
	while (i < ca_a->length)
	{
		a_index = ca_a->array[(ca_a->head + i) % ca_a->size];
		if (a_index < target_idx)
		{
			target_idx = a_index;
			target_pos = i;
		}
		i++;
	}
	return (target_pos);
}

void	calculate_target_positions(t_circular_array *ca_a, \
										t_circular_array *ca_b)
{
	int	i;
	int	target_pos;
	int	b_index;

	i = 0;
	while (i < ca_b->length)
	{
		b_index = ca_b->array[(ca_b->head + i) % ca_b->size];
		target_pos = find_initial_target_position(ca_a, b_index);
		if (target_pos == -1)
			target_pos = find_minimum_position(ca_a);
		ca_b->target_positions[(ca_b->head + i) % ca_b->size] = target_pos;
		i++;
	}
}
