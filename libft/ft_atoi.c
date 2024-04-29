/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:25:15 by jmakkone          #+#    #+#             */
/*   Updated: 2024/04/25 13:59:22 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			msing;
	long long	sum;
	long long	check;

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
		check = sum;
		sum = sum * 10 + *str - 48;
		if (sum < check && msing == 1)
			return (-1);
		if (sum < check && msing == -1)
			return (0);
		str++;
	}
	return ((int)sum * msing);
}
