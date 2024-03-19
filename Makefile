# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/10 15:30:49 by sdemaude          #+#    #+#              #
#    Updated: 2024/01/22 16:26:26 by sdemaude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
LIBDIR = libft
LIB = $(LIBDIR)/libft.a

SRC = main.c\
	push_swap.c\
	push_swap_utils.c\
	sorting_utils.c\
	find_errors.c\
	ft_push.c\
	ft_swap.c\
	ft_rotate.c\
	ft_rev_rotate.c\
	sort_stacks.c\
	sort_stacks_utils.c\
	set_target_utils.c\
	target_on_top.c

SRC_BONUS = bonus/main.c\
	bonus/checker.c\
	gnl/get_next_line.c\
	gnl/get_next_line_utils.c\
	push_swap_utils.c\
	ft_push.c\
	ft_swap.c\
	ft_rotate.c\
	ft_rev_rotate.c\
	find_errors.c
		

all : $(NAME)

$(LIB) : $(LIBDIR)
	make -C $(LIBDIR)

$(NAME) : $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f *.o
	rm -f bonus/*.o
	make clean -C $(LIBDIR) 

fclean : clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	rm -f $(LIB)

re : fclean all

bonus :  $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_BONUS) $(LIB)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIB) -o $(NAME_BONUS)

c: all clean

.PHONY: all clean fclean re bonus c
