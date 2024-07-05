# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/02 16:11:30 by jmakkone          #+#    #+#              #
#    Updated: 2024/07/05 14:18:04 by jmakkone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
NAME_BONUS  = checker
LIBFTD      = ./libft

SRC         = main.c \
			  handle_error.c \
			  handle_free.c \
			  ca_utils.c \
			  handle_input.c \
			  validate_input.c \
			  init_ca.c \
			  operators_push.c \
			  operators_swap.c \
			  operators_rotate.c \
			  operators_reverse_rotate.c \
			  sort_three.c \
			  calculate_preferred_positions.c \
			  calculate_target_positions.c \
			  calculate_cost.c \
			  do_move.c \
			  do_cheapest.c \
			  push_swap.c \
			  ft_push_swap_atoi.c \
			  is_sorted.c

SRC_BONUS   = checker_bonus.c \
			  handle_error.c \
			  handle_free.c \
			  ca_utils.c \
			  handle_input.c \
			  validate_input.c \
			  init_ca.c \
			  checker_push_bonus.c \
			  checker_swap_bonus.c \
			  checker_rotate_bonus.c \
			  checker_reverse_rotate_bonus.c \
			  ft_push_swap_atoi.c \
			  is_sorted.c

OBJ         = $(SRC:.c=.o)
OBJ_BONUS   = $(SRC_BONUS:.c=.o)
	LIBFT       = libft/libft.a

RM          = rm -f
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)

$(LIBFT):
	$(MAKE) -C $(LIBFTD)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_BONUS)

clean:
	$(MAKE) clean -C $(LIBFTD)
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	$(MAKE) fclean -C $(LIBFTD)

re: fclean all

.PHONY: all clean fclean re bonus
