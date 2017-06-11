# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elee <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/27 21:33:26 by elee              #+#    #+#              #
#    Updated: 2016/12/13 03:22:46 by elee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

PRINTF_SRCS = char.c str.c dec.c uns.c extra.c \
			  doublef.c doublee.c doubleg.c doublea.c doublev.c \
			  downcast.c put_func.c wide_conv.c \
			  flag_parser.c mfw_prec_parser.c mod_spec_parser.c \
			  postformat.c prec_calc.c preformat.c inf_nan.c \
			  ft_printf.c

CTYPE_SRCS = ft_isalnum.c ft_isalpha.c ft_iscntrl.c ft_isdigit.c ft_isgraph.c \
			 ft_islower.c ft_isprint.c ft_ispunct.c ft_isspace.c ft_isupper.c \
			 ft_isxdigit.c ft_tolower.c ft_toupper.c \
			 ft_isascii.c

STDIO_SRCS = ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
			 ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
			 get_next_line.c

STDLIB_SRCS = ft_atoi.c ft_atol.c ft_atof.c \
			  ft_itoa.c ft_ltoa.c \
			  ft_atoi_base.c ft_itoa_base.c \
			  ft_modf.c ft_rint.c

STRING_SRCS = ft_memset.c ft_bzero.c \
			  ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
			  ft_strlen.c ft_strdup.c \
			  ft_strcpy.c ft_strncpy.c ft_strlcpy.c \
			  ft_strcat.c ft_strncat.c ft_strlcat.c \
			  ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
			  ft_strcmp.c ft_strncmp.c \
			  ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
			  ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
			  ft_strequ.c ft_strnequ.c \
			  ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
			  ft_strndup.c ft_strtrimc.c \
			  ft_strlowcase.c ft_strupcase.c \
			  ft_join.c ft_split_whitespaces.c \
			  ft_strstrsplit.c \
			  ft_strresub.c ft_strrecat.c \
			  ft_twod_realloc.c ft_put_twod.c ft_strisdigit.c

STRUCT_SRCS = create_dlist.c create_node.c delete_dlist.c delete_node.c \
			  dl_display_backward.c dl_display_forward.c \
			  dl_pop_back.c dl_pop_front.c dl_push_back.c dl_push_front.c \
			  dl_size.c dl_top_back.c dl_top_front.c \
			  ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
			  ft_lstnew.c \
			  stack.c stack2.c \
			  btree.c btree2.c \
			  matrix.c matrix2.c

SORT_SRCS = bubble_sort.c insertion_sort.c selection_sort.c \
			quick_sort.c merge_sort.c heap_sort.c

MISC_SRCS = ft_bnull.c ft_free_two.c ft_free_three.c \
			ft_intnew.c ft_ptrnew.c ft_ptrlen.c \
			ft_numlen.c ft_numlen2.c ft_unsignedlen.c \
			ft_pb.c delete_func.c ft_nextchr.c ft_count_chr.c \
			ft_int_twodnew.c ft_int_twodfree.c

PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)
CTYPE_OBJS = $(CTYPE_SRCS:.c=.o)
STDIO_OBJS = $(STDIO_SRCS:.c=.o)
STDLIB_OBJS = $(STDLIB_SRCS:.c=.o)
STRING_OBJS = $(STRING_SRCS:.c=.o)
STRUCT_OBJS = $(STRUCT_SRCS:.c=.o)
SORT_OBJS = $(SORT_SRCS:.c=.o)
MISC_OBJS = $(MISC_SRCS:.c=.o)

INCS = ./includes

all: $(NAME)

$(NAME):
	mkdir -p build/
	$(CC) $(CFLAGS) -c $(addprefix printf/, $(PRINTF_SRCS)) -I$(INCS)
	$(CC) $(CFLAGS) -c $(addprefix ctype/, $(CTYPE_SRCS)) -I$(INCS)
	$(CC) $(CFLAGS) -c $(addprefix stdio/, $(STDIO_SRCS)) -I$(INCS)
	$(CC) $(CFLAGS) -c $(addprefix stdlib/, $(STDLIB_SRCS)) -I$(INCS)
	$(CC) $(CFLAGS) -c $(addprefix string/, $(STRING_SRCS)) -I$(INCS)
	$(CC) $(CFLAGS) -c $(addprefix struct/, $(STRUCT_SRCS)) -I$(INCS)
	$(CC) $(CFLAGS) -c $(addprefix sort/, $(SORT_SRCS)) -I$(INCS)
	$(CC) $(CFLAGS) -c $(addprefix misc/, $(MISC_SRCS)) -I$(INCS)
	mv $(PRINTF_OBJS) build/
	mv $(CTYPE_OBJS) build/
	mv $(STDIO_OBJS) build/
	mv $(STDLIB_OBJS) build/
	mv $(STRING_OBJS) build/
	mv $(STRUCT_OBJS) build/
	mv $(SORT_OBJS) build/
	mv $(MISC_OBJS) build/
	ar rc $(NAME) $(addprefix build/, $(PRINTF_OBJS)) \
		$(addprefix build/, $(CTYPE_OBJS)) \
		$(addprefix build/, $(STDIO_OBJS)) \
		$(addprefix build/, $(STDLIB_OBJS)) \
		$(addprefix build/, $(STRING_OBJS)) \
		$(addprefix build/, $(STRUCT_OBJS)) \
		$(addprefix build/, $(SORT_OBJS)) \
		$(addprefix build/, $(MISC_OBJS))
	ranlib $(NAME)

clean:
	/bin/rm -rf build

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
