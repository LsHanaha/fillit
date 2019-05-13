# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/18 11:50:00 by jrobin-h          #+#    #+#              #
#    Updated: 2019/02/18 13:01:35 by jrobin-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS =	main.c 					\
		validate_and_write.c	\
		preprocessing.c 		\
		checkers.c				\
		solve.c					\
		initializers.c			\
		validate_helpers.c		\
		helpers.c

HEADS =	fillit.h			\
		validate_helpers.h	\
		solve_helpers.h		\
		checkers.h			\
		initializers.h		\
		generic.h

OBJS = $(SRCS:.c=.o)

LIBNAME = ft

LIBDIR = lib$(LIBNAME)

LIBFILE = $(LIBDIR)/lib$(LIBNAME).a

CC = gcc

CLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS) $(LIBFILE)
	$(CC) -L$(LIBDIR) -l$(LIBNAME) $(OBJS) -o $(NAME)

$(OBJS): %.o : %.c $(HEADS)
	$(CC) $(CFLAGS) -c -I. -I$(LIBDIR) $<

$(LIBFILE): $(wildcard $(LIBDIR)/*.c) $(wildcard $(LIBDIR)/*.h)
	make -C $(LIBDIR)

cleannolib:
	rm -f $(OBJS)

clean: cleannolib
	make -C $(LIBDIR) clean

fclean: cleannolib
	rm -f $(NAME)
	make -C $(LIBDIR) fclean

re: fclean all
