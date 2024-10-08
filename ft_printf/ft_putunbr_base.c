/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:51:31 by jmakkone          #+#    #+#             */
/*   Updated: 2024/05/07 11:40:06 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_base_convert(unsigned long nbr, size_t baselen, char *base)
{
	int	print_count;
	int	write_check;

	print_count = 0;
	write_check = 0;
	if (nbr < baselen)
	{
		write_check = print_count;
		print_count += ft_printchar(base[nbr]);
		if (print_count < write_check)
			return (-1);
		return (print_count);
	}
	write_check = print_count;
	print_count += ft_base_convert(nbr / baselen, baselen, base);
	if (print_count < write_check)
		return (-1);
	write_check = print_count;
	print_count += ft_base_convert(nbr % baselen, baselen, base);
	if (print_count < write_check)
		return (-1);
	return (print_count);
}

int	ft_putunbr_base(unsigned long nbr, char *base)
{
	size_t	baselen;
	int		print_count;

	print_count = 0;
	baselen = ft_strlen(base);
	print_count += ft_base_convert(nbr, baselen, base);
	if (print_count == -1)
		return (-1);
	return (print_count);
}
