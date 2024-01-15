/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:22:06 by sdemaude          #+#    #+#             */
/*   Updated: 2024/01/15 18:05:43 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	init_nodes(t_stack_list *a, t_stack_list *b, char c)
{
	current_index(a);
	current_index(b);
	if (c == 'a')
	{
		set_target_a(a, b);
		cost_analysis(a, b);
		set_cheapest(a);
	}
	else if (c == 'b')
		set_target_b(a, b);
}

void	prep_for_push(t_stack_list **stack, t_stack_list *top_node, char c)
{
	printf("prep for push\n");
	while (*stack != top_node)
	{
		printf("in while\n");
		if (c == 'a')
		{
			printf("c == a\n");
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (c == 'b')
		{
			printf("c == b\n");
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	move_a_to_b(t_stack_list **a, t_stack_list **b)
{
	t_stack_list	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rr(a, b);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rrr(a, b);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a);
}

void	move_b_to_a(t_stack_list **a, t_stack_list **b)
{
	printf("move b to a\n");
	prep_for_push(a, (*b)->target_node, 'a');
	printf("after prep for push\n");
	pa(a, b);
}

void	sort_stacks(t_stack_list **a, t_stack_list **b)
{
	int		len_a;

	len_a = mod_lstsize(*a);
	if (len_a > 3 && !is_sorted(a))
	{
		pb(b, a);
		len_a--;
	}
	if (len_a > 3 && !is_sorted(a))
	{
		pb(b, a);
		len_a--;
	}
	while (len_a > 3 && !is_sorted(a))
	{
		init_nodes(*a, *b, 'a');
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes(*a, *b, 'b');
		printf("middle\n");
		move_b_to_a(a, b);
		printf("after\n");
	}
	current_index(*a);
	min_on_top(a);
}
