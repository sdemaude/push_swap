/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:19:46 by sdemaude          #+#    #+#             */
/*   Updated: 2023/12/12 10:55:59 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "Libft/libft.h"

typedef struct s_stack_list
{
	int				content;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}		t_stack_list;

int		find_error(int a, char **v);
int		check_doubles(int size, int *array);
int		check_int_maxmin(int *array, char **str);
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);


#endif 
