/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:19:35 by sdemaude          #+#    #+#             */
/*   Updated: 2023/12/13 12:59:15 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	char_to_int(int size, char **str)
{
	int	i;
	int	j;
	int	*array;

	i = 1;
	j = 0;
	array = malloc(size * sizeof(int));
	if (!array)
		return (1);
	while (str[i])
	{
		array[i - 1] = ft_atoi(str[i]);
		i++;
	}
	if (check_int_maxmin(array, str) || check_doubles(size, array))
	{
		free (array);
		return (1);
	}
	free (array);
	return (0);
}
/*
t_stack_list	tab_to_list(int size, int *array)
{

	while (size > 0)
	return ();
}

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

int	main(int ac, char **av)
{
	if (find_error(ac, av))
		return (0);
	if (char_to_int((ac - 1), av))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (0);
}
