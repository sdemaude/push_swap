# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/10 15:30:49 by sdemaude          #+#    #+#              #
#    Updated: 2024/01/05 16:49:46 by sdemaude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
OBJS = $(SRC:.c=.o)
CC = cc -Wall -Wextra -Werror -g
LIB = "libft/libft.a"

SRC = push_swap.c\
	push_swap_utils.c\
	sorting_utils.c\
	find_errors.c\
	ft_push.c\
	ft_swap.c\
	ft_rotate.c\
	ft_rev_rotate.c

$(NAME) : $(LIB) 
#	cd libft && $(MAKE)
	$(CC) $(SRC) $(LIB) -o $(NAME)

$(LIB) :
	$(MAKE) -C $$(dirname $@)

all : $(NAME)

clean :
	$(MAKE) clean -C $$(dirname $(LIB));

fclean : clean
	rm -f $(LIB)
	rm -f $(NAME)

re : fclean all
