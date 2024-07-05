/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:08:07 by jmakkone          #+#    #+#             */
/*   Updated: 2024/07/05 14:31:17 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rotate(t_circular_array *ca)
{
	int	tmp;

	if (ca_length(ca) > 1)
	{
		tmp = ca_pop(ca);
		ca_push(ca, tmp);
	}
}

void	checker_ra(t_circular_array *ca_a)
{
	rotate(ca_a);
}

void	checker_rb(t_circular_array *ca_b)
{
	rotate(ca_b);
}

void	checker_rr(t_circular_array *ca_a, t_circular_array *ca_b)
{
	rotate(ca_a);
	rotate(ca_b);
}
