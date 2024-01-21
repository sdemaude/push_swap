/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:32:28 by sdemaude          #+#    #+#             */
/*   Updated: 2024/01/21 18:14:33 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_list	*find_min(t_stack_list *stack)
{
	t_stack_list	*min_node;
	long			min_value;

	min_value = LONG_MAX;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->content < min_value)
		{
			min_value = stack->content;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack_list	*find_max(t_stack_list *stack)
{
	t_stack_list	*max_node;
	long			max_value;

	max_value = LONG_MIN;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->content > max_value)
		{
			max_value = stack->content;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

bool	is_sorted(t_stack_list **stack)
{
	t_stack_list	*current;

	if (!*stack)
		return (true);
	current = *stack;
	while (current->next != NULL)
	{
		if (current->content > current->next->content)
			return (false);
		current = current->next;
	}
	return (true);
}
/*
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
*/

void	sort_three(t_stack_list **stack)
{
	int	min;
	int	max;

	if (is_sorted(stack))
		return ;
	min = find_min(*stack)->content;
	max = find_max(*stack)->content;
	if ((*stack)->content == min)
	{
		sa(stack);
		ra(stack);
	}
	else if ((*stack)->next->content == min
		&& (*stack)->next->next->content == max)
		sa(stack);
	else if ((*stack)->next->content == max
		&& (*stack)->next->next->content == min)
		rra(stack);
	else if ((*stack)->content == max && (*stack)->next->next->content == min)
	{
		sa(stack);
		rra(stack);
	}
	else
		ra(stack);
}
