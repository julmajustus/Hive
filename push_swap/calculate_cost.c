/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 08:45:33 by jmakkone          #+#    #+#             */
/*   Updated: 2024/06/23 19:38:35 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_cost(t_circular_array *ca_a, t_circular_array *ca_b)
{
	int	i;
	int	pos_b;
	int	target_pos;

	i = 0;
	while (i < ca_b->length)
	{
		pos_b = (ca_b->head + i) % ca_b->size;
		target_pos = ca_b->target_positions[pos_b];
		ca_b->cost_b[pos_b] = i;
		if (i > ca_b->length / 2)
			ca_b->cost_b[pos_b] = (ca_b->length - i) * -1;
		ca_b->cost_a[pos_b] = target_pos;
		if (target_pos > ca_a->length / 2)
			ca_b->cost_a[pos_b] = (ca_a->length - target_pos) * -1;
		i++;
	}
}
