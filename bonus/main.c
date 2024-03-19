/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:52:57 by sdemaude          #+#    #+#             */
/*   Updated: 2024/01/22 18:36:15 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

static int	main_two(t_stack_list **a, t_stack_list **b)
{
	char			*instruction;

	instruction = get_next_line(STDIN_FILENO);
	while (instruction)
	{
		if (do_instruction(a, b, instruction) == 6)
			return (mod_lstclear(a), mod_lstclear(b), 1);
		free(instruction);
		instruction = get_next_line(STDIN_FILENO);
	}
	if (is_sorted(a) && !*b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	mod_lstclear(a);
	mod_lstclear(b);
	free(instruction);
	return (0);
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
		if (ac < 1 || find_error(ac, av) || char_to_int(ac, av, &array))
			return (0);
	arr_to_stack(&a, array, ac);
	return (main_two(&a, &b));
}
