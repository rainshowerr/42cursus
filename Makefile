# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 17:05:34 by seoshin           #+#    #+#              #
#    Updated: 2022/10/10 21:58:17 by seoshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

MLX_FLAGS	=	-L./mlx -lmlx -framework OpenGL -framework AppKit

SRCS		=	main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJS		=	$(SRCS:.c=.o)

NAME		=	so_long

$(NAME) 	:	$(OBJS)
				$(CC) $(CFLAGS) $(MLX_FLAGS) $(SRCS) -o so_long

all			:	$(NAME)

%.o			:	%.c
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				rm -f $(OBJS)

fclean		:	clean
				rm -f $(NAME)

re			:	fclean
				make all

.PHONY		:	all clean fclean re