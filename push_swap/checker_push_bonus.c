/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_push_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:20:41 by jmakkone          #+#    #+#             */
/*   Updated: 2024/07/05 14:30:36 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	checker_pa(t_circular_array *ca_a, t_circular_array *ca_b)
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
	}
}

void	checker_pb(t_circular_array *ca_a, t_circular_array *ca_b)
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
	}
}
