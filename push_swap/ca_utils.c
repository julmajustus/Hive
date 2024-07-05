/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ca_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:34:07 by jmakkone          #+#    #+#             */
/*   Updated: 2024/06/24 08:30:34 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ca_is_empty(t_circular_array *ca)
{
	return (ca->length == 0);
}

int	ca_get(t_circular_array *ca, int index)
{
	return (ca->array[(ca->head + index) % ca->size]);
}

void	ca_set(t_circular_array *ca, int index, int value)
{
	ca->array[(ca->head + index) % ca->size] = value;
}

int	ca_length(t_circular_array *ca)
{
	return (ca->length);
}
