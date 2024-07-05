/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 08:14:28 by jmakkone          #+#    #+#             */
/*   Updated: 2024/07/02 10:11:42 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_circular_array
{
	int	*array;
	int	size;
	int	head;
	int	tail;
	int	length;
	int	*target_positions;
	int	*preferred_pos;
	int	*cost_a;
	int	*cost_b;
	int	cheapest;
	int	combined_cost;
}	t_circular_array;

t_circular_array	*create_circular_array(int size);
void				err(void);
void				free_arr(char **arr);
void				free_arr_exit(char **arr);
void				free_circular_array(t_circular_array *ca);
void				handle_string(char **argv, t_circular_array **ca_a, \
													t_circular_array **ca_b);
void				handle_arr(int argc, char **argv, t_circular_array **ca_a, \
													t_circular_array **ca_b);
int					fill_ca(int argc, char **argv, t_circular_array *ca_a);
long				ft_push_swap_atoi(const char *str);
void				ca_push(t_circular_array *ca, int value);
int					ca_pop(t_circular_array *ca);
int					ca_is_empty(t_circular_array *ca);
int					is_number(char *arg);
int					is_valid(char **argv);
int					ca_get(t_circular_array *ca, int index);
void				ca_set(t_circular_array *ca, int index, int value);
int					ca_length(t_circular_array *ca);
void				sort_three(t_circular_array *ca_a);
void				leave_three(t_circular_array *ca_a, t_circular_array *ca_b);
int					is_sorted(t_circular_array *ca);
void				calculate_target_positions(t_circular_array *ca_a, \
					t_circular_array *ca_b);
void				assign_preferred_positions(t_circular_array *ca);
void				get_cost(t_circular_array *ca_a, t_circular_array *ca_b);
void				do_move(t_circular_array *ca_a, t_circular_array *ca_b, \
					int cost_a, int cost_b);
void				do_cheapest(t_circular_array *ca_a, t_circular_array *ca_b);
void				push_swap(t_circular_array *ca_a, t_circular_array *ca_b);
void				ra(t_circular_array *ca);
void				rb(t_circular_array *ca_b);
void				rr(t_circular_array *ca_a, t_circular_array *ca_b);
void				rra(t_circular_array *ca);
void				rrb(t_circular_array *ca_b);
void				rrr(t_circular_array *ca_a, t_circular_array *ca_b);
void				sa(t_circular_array *ca);
void				sb(t_circular_array *ca_b);
void				ss(t_circular_array *ca_a, t_circular_array *ca_b);
void				pa(t_circular_array *ca_a, t_circular_array *ca_b);
void				pb(t_circular_array *ca_a, t_circular_array *ca_b);
#endif
