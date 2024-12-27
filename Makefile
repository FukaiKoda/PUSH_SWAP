CC = cc

CFLAGS = -Wall -Werror -Wextra -I .

RM = rm -f

NAME = push_swap

BONUS_NAME = checker
#-------------------------------- ft_printf ---------------------------------#
PRINTF_SRC = 	check_format.c ft_printf.c ft_strchr.c putlchar.c \
				putlhex.c putlnbr.c putlptr.c  putlstr.c putlunbr.c putlhex_ul.c

PRINTF_OBJ = ${PRINTF_SRC:%.c=%.o}
#----------------------------------------------------------------------------#

#------------------------------ ft_stack ------------------------------------#
STACK_SRC = stack_tools.c stack_tools2.c

STACK_OBJ = ${STACK_SRC:%.c=%.o}
#----------------------------------------------------------------------------#

#--------------------------- bonus functions --------------------------------#
BONUS_SRC =	get_next_line.c get_next_line_utils.c checker_bonus.c

BONUS_OBJ = ${BONUS_SRC:%.c=%.o}
#----------------------------------------------------------------------------#

#------------------------------ additional ----------------------------------#
SRC =  main_tools.c ft_atoi.c ft_split.c instructe.c turk_sort.c \
		position_finder.c calculate_moves.c sort_essential.c

OBJ = ${SRC:%.c=%.o}
#----------------------------------------------------------------------------#

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${PRINTF_OBJ} ${STACK_OBJ} ${OBJ}
	${CC} ${CFLAGS} ${PRINTF_SRC} ${STACK_SRC} ${SRC} main.c -o $@

bonus: ${BONUS_OBJ} ${PRINTF_OBJ} ${STACK_OBJ} ${OBJ}
	${CC} -g ${CFLAGS} ${STACK_SRC} ${BONUS_SRC} ${SRC} ${PRINTF_SRC} -o ${BONUS_NAME}

clean:
	${RM} ${STACK_OBJ} ${PRINTF_OBJ} ${OBJ} ${BONUS_OBJ} main.o

fclean: clean
	${RM} ${NAME} ${BONUS_NAME}

re: fclean all

.PHONY: all NAME clean fclean re bonus
