/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:48:34 by sdemaude          #+#    #+#             */
/*   Updated: 2024/01/22 17:48:32 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

static int	sizeofarray(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	int				*array;
	char			**tab;
	t_stack_list	*a;
	t_stack_list	*b;

	ac--;
	av++;
	array = NULL;
	a = NULL;
	b = NULL;
	if (ac == 1 && strrchr(av[0], ' '))
	{
		tab = ft_split(av[0], ' ');
		ac = sizeofarray(tab);
		if (find_error(ac, tab) || char_to_int(ac, tab, &array))
			return (free_tab(tab), 0);
		free_tab(tab);
	}
	else
		if (find_error(ac, av) || char_to_int(ac, av, &array))
			return (0);
	arr_to_stack(&a, array, ac);
	sorting_algo(&a, &b, ac);
	mod_lstclear(&a);
	return (0);
}
