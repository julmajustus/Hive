/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_swap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:59:07 by jmakkone          #+#    #+#             */
/*   Updated: 2024/07/05 14:30:51 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap(t_circular_array *ca)
{
	int	tmp;

	if (ca_length(ca) > 1)
	{
		tmp = ca_get(ca, 0);
		ca_set(ca, 0, ca_get(ca, 1));
		ca_set(ca, 1, tmp);
	}
}

void	checker_sa(t_circular_array *ca_a)
{
	swap(ca_a);
}

void	checker_sb(t_circular_array *ca_b)
{
	swap(ca_b);
}

void	checker_ss(t_circular_array *ca_a, t_circular_array *ca_b)
{
	swap(ca_a);
	swap(ca_b);
}
