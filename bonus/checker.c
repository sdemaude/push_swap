/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:09:59 by sdemaude          #+#    #+#             */
/*   Updated: 2024/01/22 18:35:18 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

bool	is_sorted(t_stack_list **stack)
{
	t_stack_list	*current;

	if (!*stack)
		return (true);
	current = *stack;
	while (current->next != NULL)
	{
		if (current->content > current->next->content)
			return (false);
		current = current->next;
	}
	return (true);
}

int	char_to_int(int size, char **str, int **array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	*array = malloc(size * sizeof(int));
	if (!*array)
		return (1);
	while (i < size)
	{
		(*array)[i] = ft_atoi(str[i]);
		i++;
	}
	if (check_doubles(size, array) || check_int_maxmin(array, str, size))
	{
		free(*array);
		return (1);
	}
	return (0);
}

void	arr_to_stack(t_stack_list **stack, int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		mod_lstnew_back(stack, array[i]);
		i++;
	}
	free (array);
}

int	do_instruction(t_stack_list **a, t_stack_list **b, char	*instruction)
{
	if (!ft_strcmp(instruction, "pa\n"))
		pa(a, b, false);
	else if (!ft_strcmp(instruction, "pb\n"))
		pb(b, a, false);
	else if (!ft_strcmp(instruction, "sa\n"))
		sa(a, false);
	else if (!ft_strcmp(instruction, "sb\n"))
		sb(b, false);
	else if (!ft_strcmp(instruction, "ss\n"))
		ss(a, b, false);
	else if (!ft_strcmp(instruction, "ra\n"))
		ra(a, false);
	else if (!ft_strcmp(instruction, "rb\n"))
		rb(b, false);
	else if (!ft_strcmp(instruction, "rr\n"))
		rr(a, b, false);
	else if (!ft_strcmp(instruction, "rra\n"))
		rra(a, false);
	else if (!ft_strcmp(instruction, "rrb\n"))
		rrb(b, false);
	else if (!ft_strcmp(instruction, "rrr\n"))
		rrr(a, b, false);
	else
		return (write(2, "Error\n", 6));
	return (0);
}
