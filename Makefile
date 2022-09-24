# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 17:05:34 by seoshin           #+#    #+#              #
#    Updated: 2022/09/24 22:39:41 by seoshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc

CFLAGS		=	-L./mlx -lmlx -framework OpenGL -framework AppKit

SRCS		=	main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJS		=	$(SRCS:.c=.o)

NAME		=	so_long

$(NAME) 	:	$(OBJS)
				$(CC) $(CFLAGS) $(SRCS) -o so_long
				./so_long

all			:	$(NAME)

%.o			:	%.c
				$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean		:
				rm -f $(OBJS)

fclean		:	clean
				rm -f $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re