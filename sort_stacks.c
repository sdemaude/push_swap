/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:14:29 by sdemaude          #+#    #+#             */
/*   Updated: 2024/02/19 10:02:40 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	min_on_top(t_stack_list **stack)
{
	while ((*stack)->content != find_min(*stack)->content)
	{
		if (find_min(*stack)->above_median)
			ra(stack, true);
		else
			rra(stack, true);
	}
}

static void	sort_stacks_return(t_stack_list **a, t_stack_list **b)
{
	if (!is_sorted(a))
		sort_three(a);
	while (*b)
	{
		set_target_b(a, b);
		set_cost(b, a);
		set_cheapest(*b);
		target_on_top_b(a, b);
		pa(a, b, true);
	}
	min_on_top(a);
}

void	sort_stacks(t_stack_list **a, t_stack_list **b)
{
	int				i;
	int				len_a;
	t_stack_list	*biggest_node;

	i = 0;
	len_a = mod_lstsize(*a);
	biggest_node = find_max(*a);
	while (i++ < 2)
	{
		if (len_a-- > 3 && !(is_sorted(a)))
		{
			if (*a == biggest_node)
				ra(a, true);
			pb(b, a, true);
		}
	}
	while (len_a-- > 3 && !is_sorted(a))
	{
		set_target_a(a, b);
		set_cost(a, b);
		set_cheapest(*a);
		target_on_top_a(a, b);
		pb(b, a, true);
	}
	sort_stacks_return(a, b);
}
