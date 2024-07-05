/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_reverse_rotate_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:08:07 by jmakkone          #+#    #+#             */
/*   Updated: 2024/07/05 14:31:04 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	reverse_rotate(t_circular_array *ca)
{
	int	value;

	if (ca_length(ca) < 2)
		return ;
	ca->tail = (ca->tail - 1 + ca->size) % ca->size;
	value = ca->array[ca->tail];
	ca->head = (ca->head - 1 + ca->size) % ca->size;
	ca->array[ca->head] = value;
}

void	checker_rra(t_circular_array *ca)
{
	reverse_rotate(ca);
}

void	checker_rrb(t_circular_array *ca)
{
	reverse_rotate(ca);
}

void	checker_rrr(t_circular_array *ca_a, t_circular_array *ca_b)
{
	reverse_rotate(ca_a);
	reverse_rotate(ca_b);
}
