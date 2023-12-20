/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:10:33 by sdemaude          #+#    #+#             */
/*   Updated: 2023/12/20 20:25:37 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

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

	new_node = malloc(sizeof(int));
	if (!new_node)
		return ;
	new_node->content = content;
	new_node->next = NULL;
	while (*stack != NULL)
		stack = &(*stack)->next;
	*stack = new_node;
	new_node->prev = new_node->next->prev;
	new_node->prev->next = new_node;
}
