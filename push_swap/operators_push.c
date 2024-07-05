/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:20:41 by jmakkone          #+#    #+#             */
/*   Updated: 2024/06/21 01:36:45 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_circular_array *ca_a, t_circular_array *ca_b)
{
	int	value;
	int	i;

	i = ca_length(ca_a);
	if (!ca_is_empty(ca_b))
	{
		value = ca_pop(ca_b);
		while (i > 0)
		{
			ca_set(ca_a, i, ca_get(ca_a, i - 1));
			i--;
		}
		ca_set(ca_a, 0, value);
		ca_a->tail = (ca_a->tail + 1) % ca_a->size;
		ca_a->length++;
		ft_putstr_fd("pa\n", 1);
	}
}

void	pb(t_circular_array *ca_a, t_circular_array *ca_b)
{
	int	value;
	int	i;

	i = ca_length(ca_b);
	if (!ca_is_empty(ca_a))
	{
		value = ca_pop(ca_a);
		while (i > 0)
		{
			ca_set(ca_b, i, ca_get(ca_b, i - 1));
			i--;
		}
		ca_set(ca_b, 0, value);
		ca_b->tail = (ca_b->tail + 1) % ca_b->size;
		ca_b->length++;
		ft_putstr_fd("pb\n", 1);
	}
}
