/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:41:30 by jmakkone          #+#    #+#             */
/*   Updated: 2024/07/02 11:31:57 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_highest_value(t_circular_array *ca)
{
	int	i;
	int	len;
	int	highest_value;

	i = 1;
	len = ca_length(ca);
	highest_value = ca_get(ca, 0);
	while (i < len)
	{
		if (ca_get(ca, i) > highest_value)
			highest_value = ca_get(ca, i);
		i++;
	}
	return (highest_value);
}

void	leave_three(t_circular_array *ca_a, t_circular_array *ca_b)
{
	int	stack_len;
	int	push_count;
	int	i;

	assign_preferred_positions(ca_a);
	stack_len = ca_a->length;
	push_count = 0;
	i = 0;
	while (stack_len > 6 && i < stack_len && push_count < stack_len / 2)
	{
		if (ca_a->preferred_pos[i] <= stack_len / 2)
		{
			pb(ca_a, ca_b);
			push_count++;
		}
		else
			ra(ca_a);
		i++;
	}
	while (stack_len - push_count > 3)
	{
		pb(ca_a, ca_b);
		push_count++;
	}
}

void	sort_three(t_circular_array *ca)
{
	int	highest;

	if (is_sorted(ca))
		return ;
	highest = find_highest_value(ca);
	if (ca_get(ca, 0) == highest)
		ra(ca);
	else if (ca_get(ca, 1) == highest)
		rra(ca);
	if (ca_get(ca, 0) > ca_get(ca, 1))
		sa(ca);
}
