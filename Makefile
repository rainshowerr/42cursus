# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 17:05:34 by seoshin           #+#    #+#              #
#    Updated: 2022/09/13 20:50:22 by seoshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	

OBJS		=	$(SRCS:.c=.o)

NAME		=	 

$(NAME) 	:	$(OBJS)
				ar rcs $(NAME) $(OBJS)

all			:
				gcc -L./mlx -lmlx -framework OpenGL -framework AppKit main.c
				./a.out

%.o			:	%.c
				$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean		:
				rm -f $(OBJS)

fclean		:	clean
				rm -f $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re