/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:00:25 by jmakkone          #+#    #+#             */
/*   Updated: 2024/05/06 10:29:48 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str)
{
	int	print_count;

	print_count = 0;
	if (!str)
		return (write(1, "(null)", 6));
	else
	{
		while (*str)
		{
			if ((ft_printchar(*str)) == -1)
				return (-1);
			str++;
			print_count++;
		}
		return (print_count);
	}
}
