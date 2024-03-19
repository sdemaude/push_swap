/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:40:22 by sdemaude          #+#    #+#             */
/*   Updated: 2024/01/22 17:48:40 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int				i;

	i = 0;
	while (i < size)
	{
		mod_lstnew_back(stack, array[i]);
		i++;
	}
	free (array);
}

void	sorting_algo(t_stack_list **a, t_stack_list **b, int size)
{
	if (!is_sorted(a))
	{
		if (size == 2)
			sa(a, true);
		else if (size == 3)
			sort_three(a);
		else if (size > 3)
			sort_stacks(a, b);
	}
}
