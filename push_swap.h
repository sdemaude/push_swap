/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:19:46 by sdemaude          #+#    #+#             */
/*   Updated: 2023/12/17 17:52:01 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include "Libft/libft.h"

typedef struct s_stack_list
{
	int					content;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_list	*target_node;
	struct s_stack_list	*next;
	struct s_stack_list	*prev;
}	t_stack_list;

//Check errors
int				find_error(int a, char **v);
int				check_doubles(int size, int *array);
int				check_int_maxmin(int *array, char **str);

//Utils
t_stack_list	*mod_lstlast(t_stack_list *lst);

//Sorting fonctions
void			pa(t_stack_list **a, t_stack_list **b);
void			pb(t_stack_list **b, t_stack_list **a);
void			sa(t_stack_list **a);
void			sb(t_stack_list **b);
void			ss(t_stack_list **a, t_stack_list **b);
void			ra(t_stack_list **a);
void			rb(t_stack_list **b);
void			rr(t_stack_list **a, t_stack_list **b);
void			rra(t_stack_list **a);
void			rrb(t_stack_list **b);
void			rrr(t_stack_list **a, t_stack_list **b);

#endif 