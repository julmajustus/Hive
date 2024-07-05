/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:59:07 by jmakkone          #+#    #+#             */
/*   Updated: 2024/06/21 01:43:51 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sa(t_circular_array *ca_a)
{
	swap(ca_a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_circular_array *ca_b)
{
	swap(ca_b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_circular_array *ca_a, t_circular_array *ca_b)
{
	swap(ca_a);
	swap(ca_b);
	ft_putstr_fd("ss\n", 1);
}
