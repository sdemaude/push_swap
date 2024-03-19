/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:04:22 by sdemaude          #+#    #+#             */
/*   Updated: 2024/01/22 15:16:13 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	swap(t_stack_list **head)
{
	t_stack_list	*next;

	if (!*head || !(*head)->next)
		return ;
	next = (*head)->next;
	(*head)->prev = next;
	(*head)->next = next->next;
	if (next->next)
		next->next->prev = *head;
	next->next = *head;
	next->prev = NULL;
	*head = next;
}

void	sa(t_stack_list **a, bool print)
{
	swap(a);
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack_list **b, bool print)
{
	swap(b);
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack_list **a, t_stack_list **b, bool print)
{
	swap(a);
	swap(b);
	if (print)
		write(1, "ss\n", 3);
}
