# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/04 14:56:41 by jrobin-h          #+#    #+#              #
#    Updated: 2018/12/19 16:23:10 by jrobin-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FUNCS =	$(shell cat ./libft.h | grep -Eo "ft_\w+")

SRCS = $(FUNCS:=.c)

OBJS = $(SRCS:.c=.o)

INCLUDES = ./

HEADS = libft.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS): %.o : %.c $(addprefix $(INCLUDES), $(HEADS))
	$(CC) $(CFLAGS) -c -I $(INCLUDES) $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
