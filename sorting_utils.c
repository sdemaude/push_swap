/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:32:28 by sdemaude          #+#    #+#             */
/*   Updated: 2024/01/05 14:59:09 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack_list **stack)
{
	while ((*stack)->next != NULL)
	{
		if ((*stack)->content > (*stack)->next->content)
			return (0);
		(*stack) = (*stack)->next;
	}
	return (1);
}
