/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:54:38 by sdemaude          #+#    #+#             */
/*   Updated: 2024/01/22 12:39:37 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	max_value(int i, int j)
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
		current->cheapest = false;
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
