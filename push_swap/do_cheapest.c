/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cheapest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:40:42 by jmakkone          #+#    #+#             */
/*   Updated: 2024/06/21 02:29:13 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_cheapest(t_circular_array *ca_a, t_circular_array *ca_b)
{
	int	i;
	int	cost_a;
	int	cost_b;
	int	pos;

	i = 0;
	cost_a = 0;
	cost_b = 0;
	ca_b->cheapest = INT_MAX;
	while (i < ca_b->length)
	{
		pos = (ca_b->head + i) % ca_b->size;
		ca_b->combined_cost = ft_abs(ca_b->cost_a[pos]) + \
							ft_abs(ca_b->cost_b[pos]);
		if (ca_b->combined_cost < ft_abs(ca_b->cheapest))
		{
			ca_b->cheapest = ca_b->combined_cost;
			cost_a = ca_b->cost_a[pos];
			cost_b = ca_b->cost_b[pos];
		}
		i++;
	}
	do_move(ca_a, ca_b, cost_a, cost_b);
}
