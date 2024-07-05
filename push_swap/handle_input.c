/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:38:09 by jmakkone          #+#    #+#             */
/*   Updated: 2024/07/02 10:19:01 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	arr_len(char **arr)
{
	int	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

void	handle_string(char **argv, t_circular_array **ca_a, \
											t_circular_array **ca_b)
{
	char	**tmp;

	tmp = ft_split(argv[1], ' ');
	if (!is_valid(tmp))
		free_arr_exit(tmp);
	*ca_a = create_circular_array(arr_len(tmp));
	if (!*ca_a)
		free_arr_exit(tmp);
	*ca_b = create_circular_array(arr_len(tmp));
	if (!*ca_b)
	{
		free_circular_array(*ca_a);
		free_arr_exit(tmp);
	}
	if (!fill_ca(arr_len(tmp), tmp, *ca_a))
	{
		free_circular_array(*ca_a);
		free_circular_array(*ca_b);
		free_arr_exit(tmp);
	}
	free_arr(tmp);
}

void	handle_arr(int argc, char **argv, t_circular_array **ca_a, \
													t_circular_array **ca_b)
{
	if (!is_valid(&argv[1]))
		err();
	*ca_a = create_circular_array(argc - 1);
	if (!*ca_a)
		err();
	*ca_b = create_circular_array(argc - 1);
	if (!*ca_b)
	{
		free_circular_array(*ca_a);
		err();
	}
	if (!fill_ca(argc, argv, *ca_a))
	{
		free_circular_array(*ca_a);
		free_circular_array(*ca_b);
		err();
	}
}
