# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/10 15:30:49 by sdemaude          #+#    #+#              #
#    Updated: 2023/12/11 12:20:54 by sdemaude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
OBJS = $(SRC:.c=.o)
CC = cc -Wall -Wextra -Werror

SRC = push_swap.c\
	push_swap_utils.c\
	find_errors.c

%.o: %.c
	$(CC) -c $< -o $@

$(NAME) : $(OBJS)
	ar crs $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
