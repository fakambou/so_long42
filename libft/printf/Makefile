SRCS = $ ft_printf.c ft_putchar.c ft_putstr.c  ft_putnbr.c ft_puthex_low.c ft_puthex_upp.c ft_putptr.c ft_uputnbr.c ft_puthex_ptr.c\


OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs 
RM = rm -rf

all : ${NAME}

${NAME}:${OBJS}
	${AR} ${NAME} ${OBJS}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re






