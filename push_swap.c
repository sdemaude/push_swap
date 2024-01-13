/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:09:46 by sdemaude          #+#    #+#             */
/*   Updated: 2024/01/13 19:44:45 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

//MUST DELETE !!
void	ft_printstack(t_stack_list **stack)
{
	int				i;
	t_stack_list	*current;

	i = 0;
	current = *stack;
	while (current != NULL)
	{
/*		if (current->prev)
			printf("node prev = %d\n", current->prev->content);
*/		printf("node %d = %d\n", i, current->content);
/*		if (current->next)
			printf("node next = %d\n", current->next->content);
*/		current = current->next;
		i++;
	}
}

int	char_to_int(int size, char **str, int **array)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	*array = malloc(size * sizeof(int));
	if (!*array)
		return (1);
	while (i <= size)
	{
		(*array)[i - 1] = ft_atoi(str[i]);
		i++;
	}
	if (check_doubles(size, array) || check_int_maxmin(array, str, size))
	{
		printf("free?\n");
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
	while ((*stack)->prev != NULL)
		*stack = (*stack)->prev;
	free (array);
}

void	sorting_algo(t_stack_list **a, t_stack_list **b, int size)
{
	(void)b;
//	printf("in sorting_algo\n");
	if (!is_sorted(a))
	{
//		printf("is not sorted\n");
		if (size == 2)
			sa(a);
		else if (size == 3)
			sort_three(a);
//		else if (size > 3)
//			sort_stacks(a, b);
	}
}

int	main(int ac, char **av)
{
	int				size;
	int				*array;
	t_stack_list	*a;
	t_stack_list	*b;

	size = ac - 1;
	array = NULL;
	a = NULL;
	b = NULL;
	if (find_error(ac, av) || char_to_int(size, av, &array))
		return (0);
	arr_to_stack(&a, array, size);
//	ft_printstack(&a);
	sorting_algo(&a, &b, size);
//	ft_printstack(&a);
	free (a);
	free (b);
	return (0);
}

/*check if ther is a space in the av
*if yes, call split
*if no, av[i++];
*create a char** every time ....
*use strcat to concatenate them or make a loop
*to check error in every ch* & char **.
*/
