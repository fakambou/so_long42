SRCS = $ main.c map.c check_map.c flood_fill.c mlx.c fin.c
OBJS = ${SRCS:.c=.o}
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
RM = rm -rf
INCLUDES = -I/usr/include -Imlx -Iincludes
LIBFT = ./libft
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

all : ${NAME}

${NAME}:${OBJS}
	${MAKE} -C ${LIBFT}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT}/libft.a ${MLX_FLAGS} 

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} $(INCLUDES)

clean:
	${RM} ${OBJS}

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re