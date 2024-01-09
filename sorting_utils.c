/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:32:28 by sdemaude          #+#    #+#             */
/*   Updated: 2024/01/09 18:12:12 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack_list **stack)
{
	t_stack_list	*current;

	current = *stack;
	while (current->next != NULL)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_three(t_stack_list **stack)
{
	if ((*stack)->content < (*stack)->next->content)
	{
		rra(stack);
		if (!is_sorted(stack))
			sa(stack);
	}
	else if (!((*stack)->content > (*stack)->next->content
			&& ((*stack)->content > (*stack)->next->next->content)
			&& ((*stack)->next->content < (*stack)->next->next->content)))
	{
		sa(stack);
		if (!is_sorted(stack))
			rra(stack);
	}
	else
		ra(stack);
}
