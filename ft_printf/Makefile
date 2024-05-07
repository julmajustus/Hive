SRC			= ft_check_format.c \
			  ft_printchar.c \
			  ft_printstr.c \
			  ft_printdigit.c \
			  ft_printudigit.c \
			  ft_printf.c \
			  ft_putnbr_base.c \
			  ft_putunbr_base.c

OBJS		= ${SRC:.c=.o}  
NAME		= libftprintf.a       
AR			= ar rcs         
RM 			= rm -f         
CC 			= cc        
LIBFTD		= ./libft

CFLAGS 		= -Wall -Wextra -Werror

.c.o: 
			${CC} ${CFLAGS} -c -o $@ $<

all:		${NAME}


${NAME}:	${OBJS}
				@make -C ${LIBFTD}
				@cp ${LIBFTD}/libft.a .
				@mv libft.a ${NAME}
				${AR} ${NAME} ${OBJS}

clean: 
			${RM} ${OBJS} 
			@cd ${LIBFTD} && make clean

fclean: 	clean
			${RM} ${NAME}
			@cd ${LIBFTD} && make fclean
		
re:			fclean all
.PHONY:		all clean fclean re
