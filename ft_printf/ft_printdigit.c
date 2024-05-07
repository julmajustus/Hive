/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:02:09 by jmakkone          #+#    #+#             */
/*   Updated: 2024/05/06 22:21:25 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printdigit(long n, int base)
{
	int	print_count;

	print_count = 0;
	if (base == 1)
	{
		print_count += (ft_putnbr_base(n, "0123456789"));
		if (print_count == -1)
			return (-1);
		return (print_count);
	}
	return (0);
}
