/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:24:17 by jmakkone          #+#    #+#             */
/*   Updated: 2024/07/05 14:30:22 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	do_operation(char *line, t_circular_array *ca_a, \
											t_circular_array *ca_b)
{
	if (!ft_strncmp(line, "ra\n", 3))
		checker_ra(ca_a);
	else if (!ft_strncmp(line, "rb\n", 3))
		checker_rb(ca_b);
	else if (!ft_strncmp(line, "rr\n", 3))
		checker_rr(ca_a, ca_b);
	else if (!ft_strncmp(line, "rra\n", 4))
		checker_rra(ca_a);
	else if (!ft_strncmp(line, "rrb\n", 4))
		checker_rrb(ca_b);
	else if (!ft_strncmp(line, "rrr\n", 4))
		checker_rrr(ca_a, ca_b);
	else if (!ft_strncmp(line, "sa\n", 3))
		checker_sa(ca_a);
	else if (!ft_strncmp(line, "sb\n", 3))
		checker_sb(ca_b);
	else if (!ft_strncmp(line, "pa\n", 3))
		checker_pa(ca_a, ca_b);
	else if (!ft_strncmp(line, "pb\n", 3))
		checker_pb(ca_a, ca_b);
	else
		return ;
}

static int	check_operation(char *line)
{
	if (!ft_strncmp(line, "ra\n", 3))
		return (1);
	else if (!ft_strncmp(line, "rb\n", 3))
		return (1);
	else if (!ft_strncmp(line, "rr\n", 3))
		return (1);
	else if (!ft_strncmp(line, "rra\n", 4))
		return (1);
	else if (!ft_strncmp(line, "rrb\n", 4))
		return (1);
	else if (!ft_strncmp(line, "rrr\n", 4))
		return (1);
	else if (!ft_strncmp(line, "sa\n", 3))
		return (1);
	else if (!ft_strncmp(line, "sb\n", 3))
		return (1);
	else if (!ft_strncmp(line, "pa\n", 3))
		return (1);
	else if (!ft_strncmp(line, "pb\n", 3))
		return (1);
	else
		return (0);
}

static void	read_operations(t_circular_array *ca_a, t_circular_array *ca_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line || !ft_strncmp(line, "\n", 1))
		{
			if (is_sorted(ca_a) && ca_length(ca_b) == 0)
				ft_putstr_fd("OK\n", 1);
			else
				ft_putstr_fd("KO\n", 1);
			break ;
		}
		if (check_operation(line))
		{
			do_operation(line, ca_a, ca_b);
			free(line);
		}
		else
		{
			ft_putstr_fd("KO\n", 1);
			break ;
		}
	}
	free(line);
}

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
	read_operations(ca_a, ca_b);
	free_circular_array(ca_a);
	free_circular_array(ca_b);
	return (0);
}
