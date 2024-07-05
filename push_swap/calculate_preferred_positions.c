/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_preferred_positions.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 08:22:15 by jmakkone          #+#    #+#             */
/*   Updated: 2024/07/04 10:37:25 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	calculate_preferred_positions(t_circular_array *ca, \
												int *tmp, int len)
{
	int	i;
	int	j;
	int	swap;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (ca_get(ca, tmp[i]) > ca_get(ca, tmp[j]))
			{
				swap = tmp[i];
				tmp[i] = tmp[j];
				tmp[j] = swap;
			}
			j++;
		}
		i++;
	}
}

void	assign_preferred_positions(t_circular_array *ca)
{
	int	len;
	int	i;
	int	*tmp;

	i = 0;
	len = ca_length(ca);
	tmp = (int *)malloc(len * sizeof(int));
	if (!tmp)
		return ;
	while (i < len)
	{
		tmp[i] = i;
		i++;
	}
	calculate_preferred_positions(ca, tmp, len);
	i = 0;
	while (i < len)
	{
		ca->preferred_pos[tmp[i]] = i;
		i++;
	}
	free(tmp);
}
