# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 17:24:05 by seoshin           #+#    #+#              #
#    Updated: 2022/07/18 16:50:30 by seoshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_strncmp.c ft_toupper.c \
ft_tolower.c ft_strchr.c ft_strrchr.c ft_memchr.c ft_memcmp.c \
ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c

SRCS_BN		=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
				ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJS		= 	$(SRCS:.c=.o)

OBJS_BN		=	$(SRCS_BN:.c=.o)

NAME		=	 libft.a

ifdef WITH_BONUS
	OBJECTS = $(OBJS) $(OBJS_BN)
else
	OBJECTS = $(OBJS)
endif

all			:	$(NAME)

$(NAME) 	:	$(OBJECTS)
				ar rcs $(NAME) $(OBJECTS)

%.o		:		%.c
				$(CC) $(CFLAGS) -c $< -o $@

bonus		:
				make WITH_BONUS=1 all

clean		:
				rm -f $(OBJS) $(OBJS_BN)

fclean		:	clean
				rm -f $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re bonus
