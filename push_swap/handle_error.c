/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 02:25:43 by jmakkone          #+#    #+#             */
/*   Updated: 2024/07/02 11:34:02 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (1);
}
