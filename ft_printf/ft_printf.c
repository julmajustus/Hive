/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:07:15 by jmakkone          #+#    #+#             */
/*   Updated: 2024/05/07 14:40:41 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		print_count;
	va_list	argptr;

	print_count = 0;
	va_start(argptr, format);
	while (*format)
	{
		if (*format == '%')
		{
			print_count += ft_check_format(*(++format), argptr);
			if (print_count == -1)
				return (-1);
		}
		else
		{
			if ((ft_printchar(*format)) == -1)
				return (-1);
			print_count++;
		}
		if (!*format)
			return (0);
		format++;
	}
	va_end(argptr);
	if (print_count == -1)
		return (-1);
	return (print_count);
}
