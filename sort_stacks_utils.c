/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:54:24 by sdemaude          #+#    #+#             */
/*   Updated: 2024/01/15 18:05:40 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	min_on_top(t_stack_list **stack)
{
	while ((*stack)->content != find_min(*stack)->content)
	{
		if (find_min(*stack)->above_median)
			ra(stack);
		else
			rra(stack);
	}
}

t_stack_list	*get_cheapest(t_stack_list *stack)
{
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (stack);
}

void	set_cheapest(t_stack_list *stack)
{
	t_stack_list	*cheapest_node;
	long			cheapest_value;

	cheapest_value = LONG_MAX;
	if (!stack)
		return ;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->content;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	set_target_a(t_stack_list *a, t_stack_list *b)
{
	long			best_match;
	t_stack_list	*current_b;
	t_stack_list	*target_node;

	current_b = b;
	best_match = LONG_MIN;
	while (a)
	{
		while (current_b)
		{
			if (current_b->content < a->content
				&& current_b->content > best_match)
			{
				best_match = current_b->content;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

void	set_target_b(t_stack_list *a, t_stack_list *b)
{
	long			best_match;
	t_stack_list	*current_a;
	t_stack_list	*target_node;

	current_a = a;
	best_match = LONG_MAX;
	while (b)
	{
		while (current_a)
		{
			if (current_a->content > b->content
				&& current_a->content < best_match)
			{
				best_match = current_a->content;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	current_index(t_stack_list *stack)
{
	int	i;
	int	median;

	i = 0;
	median = mod_lstsize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		i++;
		stack = stack->next;
	}
}
