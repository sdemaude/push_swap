/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:04:09 by sdemaude          #+#    #+#             */
/*   Updated: 2024/01/22 15:20:10 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_list **dst, t_stack_list **src)
{
	t_stack_list	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}

void	pa(t_stack_list **a, t_stack_list **b, bool print)
{
	push(a, b);
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_stack_list **b, t_stack_list **a, bool print)
{
	push(b, a);
	if (print)
		write(1, "pb\n", 3);
}
