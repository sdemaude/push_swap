/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:19:35 by sdemaude          #+#    #+#             */
/*   Updated: 2023/12/20 20:25:29 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	char_to_int(int size, char **str, int **array, int arr_size)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	*array = malloc(size * sizeof(int));
	if (!*array)
		return (1);
	while (str[i])
	{
		*array[i - 1] = ft_atoi(str[i]);
		i++;
	}
	if (check_int_maxmin(*array, str) || check_doubles(size, *array))
	{
		free (*array);
		return (1);
	}
	arr_size = i;
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
//find if it is possible to do the same thing with an int 
int	main(int ac, char **av)
{
//	int				size;
	int				*array;
	t_stack_list	*a;
	t_stack_list	*b;

	a = NULL;
	b = NULL;
	if (find_error(ac, av) || char_to_int((ac - 1), av, &array/*, &size*/))
		return (0);
	arr_to_stack(&a, array/*, size*/);
	return (0);
}

/*
int	push_swap()
{
}*/

/*check if ther is a space in the av
*if yes, call split
*if no, av[i++];
*create a char** every time ....
*use strcat to concatenate them or make a loop
*to check error in every ch* & char **.
*/
