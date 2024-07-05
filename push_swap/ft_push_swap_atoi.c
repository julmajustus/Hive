/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_atoi.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:25:15 by jmakkone          #+#    #+#             */
/*   Updated: 2024/07/01 20:06:56 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_push_swap_atoi(const char *str)
{
	int			msing;
	long		sum;

	msing = 1;
	sum = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			msing = msing * -1;
		str++;
	}
	while (*str && ft_isdigit(*str) == 1)
	{
		sum = sum * 10 + *str - 48;
		if ((sum * msing) > INT_MAX || (sum * msing) < INT_MIN)
			return (LONG_MAX);
		str++;
	}
	return (sum * msing);
}
