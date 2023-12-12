/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:19:35 by sdemaude          #+#    #+#             */
/*   Updated: 2023/12/12 10:56:14 by sdemaude         ###   ########.fr       */
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
	if (check_int_maxmin(array, str) != 0)
		return (1);
	if (check_doubles(size, array) != 0)
		return (1);
	return (0);
}

/*int	tab_to_list()
{
}

int	push_swap()
{
}*/

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
