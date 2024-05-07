/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 08:42:13 by jmakkone          #+#    #+#             */
/*   Updated: 2024/05/06 23:11:08 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_ptr(va_list argptr)
{
	int	print_count;

	print_count = 0;
	print_count += ft_printstr("0x");
	if (print_count < 2)
		return (-1);
	return (print_count += ft_printudigit(va_arg(argptr, unsigned long), 2));
}

int	ft_check_format(const char specifier, va_list argptr)
{
	int	print_count;

	print_count = 0;
	if (specifier == 'c')
		print_count += ft_printchar(va_arg(argptr, int));
	else if (specifier == 's')
		print_count += ft_printstr(va_arg(argptr, char *));
	else if (specifier == 'd')
		print_count += ft_printdigit(va_arg(argptr, int), 1);
	else if (specifier == 'i')
		print_count += ft_printdigit(va_arg(argptr, int), 1);
	else if (specifier == 'u')
		print_count += ft_printudigit(va_arg(argptr, unsigned int), 1);
	else if (specifier == 'x')
		print_count += ft_printudigit(va_arg(argptr, unsigned int), 2);
	else if (specifier == 'X')
		print_count += ft_printudigit(va_arg(argptr, unsigned int), 3);
	else if (specifier == 'p')
		print_count += format_ptr(argptr);
	else
		print_count += ft_printchar(specifier);
	if (print_count == -1)
		return (-1);
	return (print_count);
}
