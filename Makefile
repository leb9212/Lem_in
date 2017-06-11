# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elee <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/27 21:33:26 by elee              #+#    #+#              #
#    Updated: 2016/12/15 15:49:22 by elee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = utils.c utils2.c utils3.c utils4.c \
	   free.c init.c read.c main.c dijkstra.c

OBJS = $(SRCS:.c=.o)

INCS = includes/

all: $(NAME)

$(NAME):
	make -C libft
	mkdir -p build/
	$(CC) $(CFLAGS) -c $(addprefix srcs/, $(SRCS)) -I$(INCS)
	mv $(OBJS) build/
	gcc $(addprefix build/, $(OBJS)) ./libft/libft.a -o $(NAME)

clean:
	make -C libft clean
	/bin/rm -rf build

fclean: clean
	make -C libft fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
