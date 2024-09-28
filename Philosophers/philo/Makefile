# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/31 13:33:17 by seoshin           #+#    #+#              #
#    Updated: 2023/03/31 13:36:31 by seoshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

CC		=	cc

CFLAG	=	-Wall -Werror -Wextra

SRCS	=	check.c do.c fork.c free.c init.c main.c one.c read.c utils.c

OBJS	=	$(SRCS:%.c=%.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) -o $@ $^
			
%.o		:	%.c
			$(CC) $(CFLAG) -c $< -o $@

clean	:   
			rm -f $(OBJS)
			
fclean	:	clean
			rm -f $(NAME)

re		:	fclean
			make all
			
.PHONY	:	all clean fclean re