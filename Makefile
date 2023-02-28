# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 19:13:56 by seoshin           #+#    #+#              #
#    Updated: 2023/02/28 22:02:17 by seoshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	main.c cmp_n_update.c deque.c final_sort.c go.c greedy.c input.c \
				instruction_p.c instruction_r.c instruction_rr.c instruction_s.c \
				loc_a.c q_sort.c send_to_b.c sort_small.c utils.c

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