/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:41:00 by jmakkone          #+#    #+#             */
/*   Updated: 2024/06/24 17:41:12 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_circular_array *ca)
{
	int	i;

	i = 0;
	if (ca_length(ca) <= 1)
		return (1);
	while (i < ca_length(ca) - 1)
	{
		if (ca_get(ca, i) > ca_get(ca, i + 1))
			return (0);
		i++;
	}
	return (1);
}
