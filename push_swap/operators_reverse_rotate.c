/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:08:07 by jmakkone          #+#    #+#             */
/*   Updated: 2024/06/21 01:43:17 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	rra(t_circular_array *ca)
{
	reverse_rotate(ca);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_circular_array *ca)
{
	reverse_rotate(ca);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_circular_array *ca_a, t_circular_array *ca_b)
{
	reverse_rotate(ca_a);
	reverse_rotate(ca_b);
	ft_putstr_fd("rrr\n", 1);
}
