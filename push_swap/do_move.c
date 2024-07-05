/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:12:08 by jmakkone          #+#    #+#             */
/*   Updated: 2024/06/21 01:45:38 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rrr(t_circular_array *ca_a, t_circular_array *ca_b, \
											int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(ca_a, ca_b);
	}
}

static void	do_rr(t_circular_array *ca_a, t_circular_array *ca_b, \
											int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(ca_a, ca_b);
	}
}

static void	do_ra(t_circular_array *ca_a, int *cost)
{
	while (*cost != 0)
	{
		if (*cost > 0)
		{
			ra(ca_a);
			(*cost)--;
		}
		else
		{
			rra(ca_a);
			(*cost)++;
		}
	}
}

static void	do_rb(t_circular_array *ca_b, int *cost)
{
	while (*cost != 0)
	{
		if (*cost > 0)
		{
			rb(ca_b);
			(*cost)--;
		}
		else
		{
			rrb(ca_b);
			(*cost)++;
		}
	}
}

void	do_move(t_circular_array *ca_a, t_circular_array *ca_b, \
											int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rrr(ca_a, ca_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rr(ca_a, ca_b, &cost_a, &cost_b);
	do_ra(ca_a, &cost_a);
	do_rb(ca_b, &cost_b);
	pa(ca_a, ca_b);
}
