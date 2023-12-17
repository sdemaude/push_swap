/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:04:22 by sdemaude          #+#    #+#             */
/*   Updated: 2023/12/17 17:51:25 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack_list **head)
{
	if (!head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->next->prev = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack_list **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack_list **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack_list **a, t_stack_list **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
