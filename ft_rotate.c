/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:03:57 by sdemaude          #+#    #+#             */
/*   Updated: 2024/01/22 15:16:11 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack_list **stack)
{
	t_stack_list	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = mod_lstlast(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	ra(t_stack_list **a, bool print)
{
	rotate(a);
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_stack_list **b, bool print)
{
	rotate(b);
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_stack_list **a, t_stack_list **b, bool print)
{
	rotate(a);
	rotate(b);
	if (print)
		write(1, "rr\n", 3);
}
