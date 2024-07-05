/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:47:48 by jmakkone          #+#    #+#             */
/*   Updated: 2024/07/02 08:54:50 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_lowest_position(t_circular_array *ca)
{
	int		i;
	int		len;
	int		lowest_value;
	int		lowest_pos;
	int		value;

	i = 0;
	len = ca_length(ca);
	lowest_value = INT_MAX;
	lowest_pos = 0;
	while (i < len)
	{
		value = ca_get(ca, i);
		if (value < lowest_value)
		{
			lowest_value = value;
			lowest_pos = i;
		}
		i++;
	}
	return (lowest_pos);
}

void	shift_stack(t_circular_array *ca_a)
{
	int	lowest_pos;
	int	len;

	lowest_pos = get_lowest_position(ca_a);
	len = ca_length(ca_a);
	if (lowest_pos > len / 2)
	{
		while (lowest_pos < len)
		{
			rra(ca_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(ca_a);
			lowest_pos--;
		}
	}
}

void	push_swap(t_circular_array *ca_a, t_circular_array *ca_b)
{
	leave_three(ca_a, ca_b);
	sort_three(ca_a);
	while (ca_length(ca_b) > 0)
	{
		calculate_target_positions(ca_a, ca_b);
		get_cost(ca_a, ca_b);
		do_cheapest(ca_a, ca_b);
	}
	if (!is_sorted(ca_a))
		shift_stack(ca_a);
}
