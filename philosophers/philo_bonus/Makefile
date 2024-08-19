# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/02 16:11:30 by jmakkone          #+#    #+#              #
#    Updated: 2024/08/19 16:48:16 by jmakkone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME_BONUS      = philo_bonus
SRC_DIR         = src
SRC_BONUS_DIR   = src_bonus
INC_DIR         = includes

SRC_BONUS       = $(SRC_BONUS_DIR)/main_bonus.c \
				  $(SRC_BONUS_DIR)/validate_input_bonus.c \
				  $(SRC_BONUS_DIR)/handle_errors_bonus.c \
				  $(SRC_BONUS_DIR)/init_data_bonus.c \
				  $(SRC_BONUS_DIR)/routine_bonus.c \
				  $(SRC_BONUS_DIR)/thread_handler_bonus.c \
				  $(SRC_BONUS_DIR)/thread_routines_bonus.c \
				  $(SRC_BONUS_DIR)/monitor_bonus.c \
				  $(SRC_BONUS_DIR)/start_routine_bonus.c \
				  $(SRC_BONUS_DIR)/utils_bonus.c

OBJ_DIR         = obj
OBJ_BONUS       = $(SRC_BONUS:$(SRC_BONUS_DIR)/%.c=$(OBJ_DIR)/%.o)

RM              = rm -f
CC              = cc
CFLAGS          = -Wall -Wextra -Werror -pthread \
				  -I$(INC_DIR) 


all:	$(NAME_BONUS)


$(OBJ_DIR)/%.o: $(SRC_BONUS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME_BONUS): $(OBJ_BONUS) 
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re
