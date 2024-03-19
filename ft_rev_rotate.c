/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:03:42 by sdemaude          #+#    #+#             */
/*   Updated: 2024/01/22 15:16:08 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack_list **stack)
{
	t_stack_list	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = mod_lstlast(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack_list **a, bool print)
{
	rev_rotate(a);
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_list **b, bool print)
{
	rev_rotate(b);
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack_list **a, t_stack_list **b, bool print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (print)
		write(1, "rrr\n", 4);
}
