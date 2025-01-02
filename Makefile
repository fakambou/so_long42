SRCS = $ main.c map.c check_map.c flood_fill.c
OBJS = ${SRCS:.c=.o}
NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf
INCLUDES = -Iincludes
LIBFT = ./libft

all : ${NAME}

${NAME}:${OBJS}
	${MAKE} -C ${LIBFT}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT}/libft.a

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} $(INCLUDES)

clean:
	${RM} ${OBJS}

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re