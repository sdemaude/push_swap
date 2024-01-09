/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:32:28 by sdemaude          #+#    #+#             */
/*   Updated: 2024/01/09 13:10:03 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack_list **stack)
{
	while ((*stack)->next != NULL)
	{
		if ((*stack)->content > (*stack)->next->content)
			return (0);
		(*stack) = (*stack)->next;
	}
	return (1);
}

void	sort_three(t_stack_list **stack)
{
	printf("in sort three\n");
	if ((*stack)->content < (*stack)->next->content)
	{
		rra(stack);
		if (!is_sorted(stack))
			sa(stack);
	}
	else if (((*stack)->content > (*stack)->next->content)
		&& ((*stack)->next->next->content > (*stack)->next->content))
	{
		sa(stack);
		if (!is_sorted(stack))
			rra(stack);
	}
	else
		ra(stack);
}
