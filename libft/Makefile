# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 17:24:05 by seoshin           #+#    #+#              #
#    Updated: 2022/07/13 16:16:49 by seoshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC	= gcc

CFLAGS	= -Wall -Wextra -Werror

SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_strncmp.c ft_toupper.c \
ft_tolower.c ft_strchr.c ft_strrchr.c ft_memchr.c ft_memcmp.c \
ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c

OBJS	= $(SRCS:.c=.o)

INCLUDES	= ./libft.h

NAME	= libft.a

.c.o:
	$(GCC) $(CFLAGS) -c $< -o $(<:.c=.o) -I INCLUDES

$(NAME):	$(OBJS)
		ar rc $(NAME) $(OBJS)

all :	$(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re