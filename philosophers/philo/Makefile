# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/02 16:11:30 by jmakkone          #+#    #+#              #
#    Updated: 2024/08/19 16:48:44 by jmakkone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME            = philo
SRC_DIR         = src
INC_DIR         = includes

SRC             = $(SRC_DIR)/main.c \
				  $(SRC_DIR)/validate_input.c \
				  $(SRC_DIR)/handle_errors.c \
				  $(SRC_DIR)/init_data.c \
				  $(SRC_DIR)/routine.c \
				  $(SRC_DIR)/monitor.c \
				  $(SRC_DIR)/start_routine.c \
				  $(SRC_DIR)/utils.c

OBJ_DIR         = obj
OBJ             = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

RM              = rm -f
CC              = cc
CFLAGS          = -Wall -Wextra -Werror -pthread \
				  -I$(INC_DIR)


all:	$(NAME)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
