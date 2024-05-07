/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printudigit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:02:09 by jmakkone          #+#    #+#             */
/*   Updated: 2024/05/06 22:45:59 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printudigit(unsigned long n, int base)
{
	int	print_count;

	print_count = 0;
	if (base == 1)
	{
		print_count = (ft_putunbr_base(n, "0123456789"));
		if (print_count == -1)
			return (-1);
		return (print_count);
	}
	else if (base == 2)
	{
		print_count = (ft_putunbr_base(n, "0123456789abcdef"));
		if (print_count == -1)
			return (-1);
		return (print_count);
	}
	else if (base == 3)
	{
		print_count = (ft_putunbr_base(n, "0123456789ABCDEF"));
		if (print_count == -1)
			return (-1);
		return (print_count);
	}
	return (0);
}
