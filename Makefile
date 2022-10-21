# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 17:05:34 by seoshin           #+#    #+#              #
#    Updated: 2022/10/21 18:28:11 by seoshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

MLX_FLAGS	=	-L./mlx -lmlx -framework OpenGL -framework AppKit

SRCS		=	main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
				util_init.c util_key_hook.c util_map_check.c util_print_or_destroy.c \
				util_others.c

OBJS		=	$(SRCS:.c=.o)

NAME		=	so_long

all			:	$(NAME)

$(NAME) 	:	$(OBJS)
				$(CC) $(CFLAGS) $(MLX_FLAGS) $(SRCS) -o so_long

%.o			:	%.c
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				rm -f $(OBJS)

fclean		:	clean
				rm -f $(NAME)

re			:	fclean
				make all

.PHONY		:	all clean fclean re