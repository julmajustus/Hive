/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 08:12:51 by jmakkone          #+#    #+#             */
/*   Updated: 2024/07/02 10:36:53 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_circular_array	*ca_a;
	t_circular_array	*ca_b;

	if (argc < 2)
		return (0);
	if (!argv || !*argv)
		err();
	if (argc == 2)
		handle_string(argv, &ca_a, &ca_b);
	else
		handle_arr(argc, argv, &ca_a, &ca_b);
	if (!is_sorted(ca_a))
		push_swap(ca_a, ca_b);
	free_circular_array(ca_a);
	free_circular_array(ca_b);
	return (0);
}
