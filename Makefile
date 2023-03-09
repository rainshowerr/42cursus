# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/07 16:49:08 by seoshin           #+#    #+#              #
#    Updated: 2023/02/20 23:33:05 by seoshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	util_functions.c ft_c_write.c ft_s_write.c ft_p_write.c ft_di_write.c ft_u_write.c ft_xx_write.c ft_printf.c

OBJS		=	$(SRCS:.c=.o)

NAME		=	 libftprintf.a

$(NAME) 	:	$(OBJS)
				ar rcs $(NAME) $(OBJS)

all			:	$(NAME)

%.o			:	%.c
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				rm -f $(OBJS)

fclean		:	clean
				rm -f $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re
