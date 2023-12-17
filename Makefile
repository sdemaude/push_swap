# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/10 15:30:49 by sdemaude          #+#    #+#              #
#    Updated: 2023/12/13 15:13:11 by sdemaude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
OBJS = $(SRC:.c=.o)
CC = cc -Wall -Wextra -Werror
LIB = "Libft/libft.a"

SRC = push_swap.c\
	push_swap_utils.c\
	find_errors.c

%.o: %.c
	$(CC) -c $< -o $@

$(NAME) : $(OBJS) $(LIB)
	cp $(LIB) $(NAME)
	ar rs $(NAME) $(OBJS)

$(LIB) :
	$(MAKE) -C $$(dirname $@)

all : $(NAME)

clean :
	$(MAKE) clean -C $$(dirname $(LIB));
	rm -f $(OBJS)

fclean : clean
	rm -f $(LIB)
	rm -f $(NAME)

re : fclean all
