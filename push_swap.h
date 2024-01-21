/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:48:56 by sdemaude          #+#    #+#             */
/*   Updated: 2024/01/21 17:53:23 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack_list
{
	int					content;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_list	*target;
	struct s_stack_list	*prev;
	struct s_stack_list	*next;
}	t_stack_list;

//Check Errors
int				find_error(int a, char **v);
int				check_doubles(int size, int **array);
int				check_int_maxmin(int **array, char **str, int size);

//Mod_LibFt
int				mod_lstsize(t_stack_list *lst);
void			mod_lstnew_back(t_stack_list **stack, int content);
t_stack_list	*mod_lstlast(t_stack_list *lst);

//Sorting Utils
bool			is_sorted(t_stack_list **stack);
void			sort_three(t_stack_list **stack);
void			sort_stacks(t_stack_list **a, t_stack_list **b);

//Stack Utils
t_stack_list	*find_max(t_stack_list *stack);
t_stack_list	*find_min(t_stack_list *stack);

//Sorting Fonctions
void			pa(t_stack_list **a, t_stack_list **b);
void			pb(t_stack_list **b, t_stack_list **a);
void			sa(t_stack_list **a);
void			sb(t_stack_list **b);
void			ss(t_stack_list **a, t_stack_list **b);
void			ra(t_stack_list **a);
void			rb(t_stack_list **b);
void			rr(t_stack_list	**a, t_stack_list **b);
void			rra(t_stack_list **a);
void			rrb(t_stack_list **b);
void			rrr(t_stack_list **a, t_stack_list **b);

#endif
