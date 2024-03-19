/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:03:06 by sdemaude          #+#    #+#             */
/*   Updated: 2024/01/22 16:24:25 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

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

//Main
int				char_to_int(int size, char **str, int **array);
void			arr_to_stack(t_stack_list **stack, int *array, int size);
void			sorting_algo(t_stack_list **a, t_stack_list **b, int size);

int				do_instruction(t_stack_list **a, t_stack_list **b,
					char	*instruction);

//Mod_LibFt
int				mod_lstsize(t_stack_list *lst);
void			mod_lstnew_back(t_stack_list **stack, int content);
t_stack_list	*mod_lstlast(t_stack_list *lst);
void			mod_lstclear(t_stack_list **lst);

//Sorting Utils
bool			is_sorted(t_stack_list **stack);

//Sorting Fonctions
void			pa(t_stack_list **a, t_stack_list **b, bool print);
void			pb(t_stack_list **b, t_stack_list **a, bool print);
void			sa(t_stack_list **a, bool print);
void			sb(t_stack_list **b, bool print);
void			ss(t_stack_list **a, t_stack_list **b, bool print);
void			ra(t_stack_list **a, bool print);
void			rb(t_stack_list **b, bool print);
void			rr(t_stack_list	**a, t_stack_list **b, bool print);
void			rra(t_stack_list **a, bool print);
void			rrb(t_stack_list **b, bool print);
void			rrr(t_stack_list **a, t_stack_list **b, bool print);

#endif
