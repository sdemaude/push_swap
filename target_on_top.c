/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_on_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:02:25 by sdemaude          #+#    #+#             */
/*   Updated: 2024/01/22 15:19:28 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	finish_target_on_top_a(t_stack_list **a, t_stack_list **b,
		t_stack_list *cheapest)
{
	while (*a != cheapest || *b != cheapest->target)
	{
		is_above_median(*a);
		is_above_median(*b);
		if (*a == cheapest && cheapest->target->above_median == true)
			rb(b, true);
		else if (*a == cheapest && cheapest->target->above_median == false)
			rrb(b, true);
		else if (*b == cheapest->target && cheapest->above_median == true)
			ra(a, true);
		else
			rra(a, true);
	}
}

static void	finish_target_on_top_b(t_stack_list **a, t_stack_list **b,
			t_stack_list *cheapest)
{
	while (*b != cheapest || *a != cheapest->target)
	{
		is_above_median(*a);
		is_above_median(*b);
		if (*b == cheapest && cheapest->target->above_median == true)
			ra(a, true);
		else if (*b == cheapest && cheapest->target->above_median == false)
			rra(a, true);
		else if (*a == cheapest->target && cheapest->above_median == true)
			rb(b, true);
		else
			rrb(b, true);
	}
}

void	target_on_top_a(t_stack_list **a, t_stack_list **b)
{
	t_stack_list	*cheapest;

	cheapest = get_cheapest(*a);
	while (*a != cheapest && *b != cheapest->target)
	{
		is_above_median(*a);
		is_above_median(*b);
		if (cheapest->above_median == true
			&& cheapest->target->above_median == true)
			rr(a, b, true);
		else if (cheapest->above_median == false
			&& cheapest->target->above_median == false)
			rrr(a, b, true);
		else
		{
			if (cheapest->above_median == true)
				ra(a, true);
			else
				rra(a, true);
		}
	}
	finish_target_on_top_a(a, b, cheapest);
}

void	target_on_top_b(t_stack_list **a, t_stack_list **b)
{
	t_stack_list	*cheapest;

	cheapest = get_cheapest(*b);
	while (*b != cheapest && *a != cheapest->target)
	{
		is_above_median(*a);
		is_above_median(*b);
		if (cheapest->above_median == true
			&& cheapest->target->above_median == true)
			rr(a, b, true);
		else if (cheapest->above_median == false
			&& cheapest->target->above_median == false)
			rrr(a, b, true);
		else
		{
			if (cheapest->above_median == true)
				rb(b, true);
			else
				rrb(b, true);
		}
	}
	finish_target_on_top_b(a, b, cheapest);
}
