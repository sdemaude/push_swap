/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:10:33 by sdemaude          #+#    #+#             */
/*   Updated: 2024/01/09 11:58:23 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_list	*mod_lstlast(t_stack_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	mod_lstnew_back(t_stack_list **stack, int content)
{
	t_stack_list	*new_node;

	new_node = malloc(sizeof(t_stack_list));
	if (!new_node)
		return ;
	new_node->content = content;
	new_node->next = NULL;
	if (*stack == NULL)
	{
		*stack = new_node;
		new_node->prev = NULL;
		return ;
	}
	while ((*stack)->next != NULL)
		*stack = (*stack)->next;
	(*stack)->next = new_node;
	new_node->prev = *stack;
}
