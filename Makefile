# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/10 15:30:49 by sdemaude          #+#    #+#              #
#    Updated: 2024/01/21 17:53:59 by sdemaude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
OBJ = $(SRC:.c=.o)
LIBDIR = libft
LIB = $(LIBDIR)/libft.a

SRC = push_swap.c\
	push_swap_utils.c\
	sorting_utils.c\
	find_errors.c\
	ft_push.c\
	ft_swap.c\
	ft_rotate.c\
	ft_rev_rotate.c\
	sort_stacks.c\
#	sort_stacks_utils.c

all : $(NAME)

$(LIB) : $(LIBDIR)
	make -C $(LIBDIR)

$(NAME) : $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f *.o
	make clean -C $(LIBDIR) 

fclean : clean
	rm -f $(NAME)
	rm -f $(LIB)

re : fclean all

c: all clean

.PHONY: all clean fclean re c
