GCC	= gcc

CFLAGS	= -Wall -Wextra -Werror

SRCS	= $(wildcard *.c)

OBJS	= ${SRCS:.c=.o}

INCLUDES	= includes

NAME	= libft.a

.c.o:
	${GCC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCLUDES}

${NAME}:	${OBJS}
		ar rc ${NAME} ${OBJS}

all :	${NAME}

clean:
	rm -f ${OBJS}

fclean:		clean
		rm -f ${NAME}

re:	fclean all
