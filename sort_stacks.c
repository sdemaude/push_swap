/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:22:06 by sdemaude          #+#    #+#             */
/*   Updated: 2024/01/13 19:44:40 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	find_min(t_stack_list *stack)
{

}

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

void	set_cheapest(t_stack_list *stack)
{
	t_stack_list	cheapest;

	while ()
	{
	}
}

void	cost_analysis(t_stack_list *a, t_stack_list *b)
{}

void	set_target(t_stack_list *a, t_stack_list *b)
{}

void	current_index(t_stack_list *stack)
{}

void	move_a_to_b()
{}

void	move_b_to_a()
{}

void	init_nodes(t_stack_list *a, t_stack_list *b, char c)
{
	current_index(a);
	current_index(b);
	set_target(a, b);
	if (c == 'a')
	{
		cost_analysis(a, b);
		set_cheapest(a);
	}
}

void	prep_for_push()
{}

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
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
