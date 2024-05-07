/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:30:51 by jmakkone          #+#    #+#             */
/*   Updated: 2024/05/07 11:38:18 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int			ft_printf(const char *format, ...);
int			ft_check_format(const char spcecifier, va_list ptr);
int			ft_printchar(int c);
int			ft_printstr(char *str);
int			ft_printdigit(long n, int base);
int			ft_printudigit(unsigned long n, int base);
int			ft_putnbr_base(long nbr, char *base);
int			ft_putunbr_base(unsigned long nbr, char *base);
#endif
