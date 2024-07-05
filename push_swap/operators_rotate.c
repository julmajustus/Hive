/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:08:07 by jmakkone          #+#    #+#             */
/*   Updated: 2024/06/21 02:23:05 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_circular_array *ca)
{
	int	tmp;

	if (ca_length(ca) > 1)
	{
		tmp = ca_pop(ca);
		ca_push(ca, tmp);
	}
}

void	ra(t_circular_array *ca_a)
{
	rotate(ca_a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_circular_array *ca_b)
{
	rotate(ca_b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_circular_array *ca_a, t_circular_array *ca_b)
{
	rotate(ca_a);
	rotate(ca_b);
	ft_putstr_fd("rr\n", 1);
}
