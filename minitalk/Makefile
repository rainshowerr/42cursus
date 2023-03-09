# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 18:18:33 by seoshin           #+#    #+#              #
#    Updated: 2023/02/13 22:00:24 by seoshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc

CFLAG		=	-Wall -Wextra -Werror

NAME		=	server client

SRCS		=	server.c\
				utils.c\
				client.c

SRCS_BN		=	server_bonus.c\
				client_bonus.c\

OBJS		=	$(SRCS:.c=.o)
OBJS_BN		=	$(SRCS_BN:.c=.o)

ifdef WITH_BONUS
	OBJECTS = $(OBJS) $(OBJS_BN)
else
	OBJECTS = $(OBJS)
endif

all			:	$(NAME)

.c.o		:
				$(CC) $(CFLAG) -c $< -o $@

$(NAME) 	:	$(OBJECTS)

ifneq ($(OBJECTS), $(OBJS))
	$(CC) $(CFLAG) -o client client_bonus.o utils.o
	$(CC) $(CFLAG) -o server server_bonus.o utils.o
else
	$(CC) $(CFLAG) -o client client.o utils.o
	$(CC) $(CFLAG) -o server server.o utils.o
endif

clean		:
				rm -f $(OBJS) $(OBJS_BN)

fclean		:	clean
				rm -f $(NAME)

re			:	fclean
				make all

bonus		:
				make WITH_BONUS=1 all

.PHONY		:	all clean fclean re bonus