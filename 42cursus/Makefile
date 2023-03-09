# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 19:13:56 by seoshin           #+#    #+#              #
#    Updated: 2023/03/06 18:28:38 by seoshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	main.c deque.c greedy.c input.c input_check.c q_sort.c send_to_b.c \
				sort_2345.c sort.c loc_a.c cmp_n_update.c final_sort.c utils.c \
				instruction_p.c instruction_r.c instruction_rr.c instruction_s.c

OBJS		=	$(SRCS:.c=.o)

NAME		=	push_swap

all			:	$(NAME)

$(NAME) 	:	$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o push_swap

%.o			:	%.c
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				rm -f $(OBJS)

fclean		:	clean
				rm -f $(NAME)

re			:	fclean
				make all

.PHONY		:	all clean fclean re