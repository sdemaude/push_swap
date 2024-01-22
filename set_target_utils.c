/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_target_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:04:09 by sdemaude          #+#    #+#             */
/*   Updated: 2024/01/22 11:53:52 by sdemaude         ###   ########.fr       */
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
