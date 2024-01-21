/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:14:29 by sdemaude          #+#    #+#             */
/*   Updated: 2024/01/21 22:22:35 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_list	*close_bigger(t_stack_list **stack, t_stack_list *node)
{
	int				value;
	long			closest_bigger;
	t_stack_list	*closest_node;
	t_stack_list	*current;

	value = node->content;
	current = *stack;
	closest_bigger = LONG_MIN;
	closest_node = current;
	while (current)
	{
		if (current->content > value && (closest_bigger == LONG_MIN
				|| current->content < closest_bigger))
		{
			closest_node = current;
			closest_bigger = current->content;
		}
		current = current->next;
	}
	if (closest_bigger != LONG_MIN)
		return (closest_node);
	else
		return (find_min(*stack));
}

t_stack_list	*close_smaller(t_stack_list **stack, t_stack_list *node)
{
	int				value;
	long			closest_smaller;
	t_stack_list	*closest_node;
	t_stack_list	*current;

	value = node->content;
	closest_smaller = LONG_MAX;
	current = *stack;
	closest_node = current;
	while (current)
	{
		if (current->content < value && (closest_smaller == LONG_MAX
				|| current->content > closest_smaller))
		{
			closest_node = current;
			closest_smaller = current->content;
		}
		current = current->next;
	}
	if (closest_smaller != LONG_MAX)
		return (closest_node);
	else
		return (find_max(*stack));
}

void	set_target_a(t_stack_list **a, t_stack_list **b)
{
	t_stack_list	*current;

	current = *a;
	while (current)
	{
		current->target = close_smaller(b, current);
		current = current->next;
	}
}

void	set_target_b(t_stack_list **a, t_stack_list **b)
{
	t_stack_list	*current;

	current = *b;
	while (current)
	{
		current->target = close_bigger(a, current);
		current = current->next;
	}
}

void	is_above_median(t_stack_list *stack)
{
	int				i;
	int				median;
	t_stack_list	*current;

	i = 0;
	median = mod_lstsize(stack) / 2;
	current = stack;
	while (current)
	{
		current->index = i;
		if (i <= median)
			current->above_median = true;
		else
			current->above_median = false;
		i++;
		current = current->next;
	}
}

int	max_value(int i, int j)
{
	if (i > j)
		return (i);
	else
		return (j);
}

void	set_cost(t_stack_list **src, t_stack_list **dst)
{
	int				len_src;
	int				len_dst;
	t_stack_list	*current;

	len_src = mod_lstsize(*src);
	len_dst = mod_lstsize(*dst);
	current = *src;
	is_above_median(*src);
	is_above_median(*dst);
	while (current)
	{
		if (current->above_median && current->target->above_median)
			current->push_cost = max_value(current->index,
					current->target->index);
		else if (!current->above_median && !current->target->above_median)
			current->push_cost = max_value(len_src - current->index,
					len_dst - current->target->index);
		else if (current->above_median && !current->target->above_median)
			current->push_cost = current->index
				+ len_dst - current->target->index;
		else
			current->push_cost = len_src - current->index
				+ current->target->index;
/*		if (current->above_median)
			current->push_cost = current->index;
		else
			current->push_cost = len_src - current->index;

		if (current->target->above_median)
			current->push_cost += current->target->index;
		else
			current->push_cost += len_dst - current->target->index;
*/
	current = current->next;
	}
}

void	set_cheapest(t_stack_list *stack)
{
	long			cheapest_value;
	t_stack_list	*cheapest_node;
	t_stack_list	*current;

	cheapest_value = LONG_MAX;
	current = stack;
	cheapest_node = current;
	while (current)
	{
		if (current->push_cost < cheapest_value && current != find_max(stack))
		{
			cheapest_value = current->push_cost;
			cheapest_node = current;
		}
		current = current->next;
	}
	cheapest_node->cheapest = true;
}

t_stack_list	*get_cheapest(t_stack_list *stack)
{
	t_stack_list	*current;

	current = stack;
	while (current)
	{
		if (current->cheapest == true)
			return (current);
		current = current->next;
	}
	return (NULL);
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
			rr(a, b);
		else if (cheapest->above_median == false
			&& cheapest->target->above_median == false)
			rrr(a, b);
		else
		{
			if (mod_lstsize(*a) < mod_lstsize(*b))
			{
				if (cheapest->above_median == true)
					ra(a);
				else
					rra(a);
			}
			else
			{
				if (cheapest->target->above_median == true)
				{
					rb(b);
				}
				else
					rrb(b);
			}
		}
	}
	while (*a != cheapest || *b != cheapest->target)
	{
		is_above_median(*a);
		is_above_median(*b);
		if (*a == cheapest && cheapest->target->above_median == true)
			rb(b);
		else if (*a == cheapest && cheapest->target->above_median == false)
			rrb(b);
		else if (*b == cheapest->target && cheapest->above_median == true)
			ra(a);
		else
			rra(a);
	}
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
			rr(a, b);
		else if (cheapest->above_median == false
			&& cheapest->target->above_median == false)
			rrr(a, b);
		else
		{
			if (mod_lstsize(*b) < mod_lstsize(*a))
			{
				if (cheapest->above_median == true)
					rb(b);
				else
					rrb(b);
			}
			else
			{
				if (cheapest->target->above_median == true)
				{
					ra(a);
				}
				else
					rra(a);
			}
		}
	}
	while (*b != cheapest || *a != cheapest->target)
	{
		is_above_median(*a);
		is_above_median(*b);
		if (*b == cheapest && cheapest->target->above_median == true)
			ra(a);
		else if (*b == cheapest && cheapest->target->above_median == false)
			rra(a);
		else if (*a == cheapest->target && cheapest->above_median == true)
			rb(b);
		else
			rrb(b);
	}
/*	while (*a != (*b)->target)
	{
		is_above_median(*a);
		if ((*b)->target->above_median == true)
			ra(a);
		else if ((*b)->target->above_median == false)
			rra(a);
	}
*/
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

void	sort_stacks(t_stack_list **a, t_stack_list **b)
{
	int				len_a;
	t_stack_list	*biggest_node;

	len_a = mod_lstsize(*a);
	biggest_node = find_max(*a);
	if (len_a-- > 3 && !(is_sorted(a)))
	{
		if (*a == biggest_node)
			ra(a);
		pb(b, a);
	}
	if (len_a-- > 3 && !(is_sorted(a)))
	{
		if (*a == biggest_node)
			ra(a);
		pb(b, a);
	}
	while (len_a-- > 3 && !is_sorted(a))
	{
		set_target_a(a, b);
		set_cost(a, b);
		set_cheapest(*a);
		target_on_top_a(a, b);
		pb(b, a);
	}
	if (!is_sorted(a))
		sort_three(a);
	while (*b)
	{
		set_target_b(a, b);
		set_cost(b, a);
		set_cheapest(*b);
		target_on_top_b(a, b);
		pa(a, b);
	}
	min_on_top(a);
}
