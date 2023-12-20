/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:32:16 by sdemaude          #+#    #+#             */
/*   Updated: 2023/12/17 18:56:48 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_error(int a, char **v)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < a)
	{
		while (v[i][j])
		{
			if (!(v[i][j] >= '0' && v[i][j] <= '9') && (v[i][0] != '-')
				&& (v[i][0] != '+'))
				return (write(2, "Error\n", 6));
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int	check_doubles(int size, int *array)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size - 1)
	{
		while (j < size)
		{
			if (array[i] == array[j])
				return (write(2, "Error\n", 6));
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int	mod_strcmp(char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1[i] == '-' && s2[j] == '-')
	{
		i++;
		j++;
	}
	else if ((s1[i] == '+') || (s1[i] == '-' && s1[i + 1] == '0'))
		i++;
	while (s1[i] == '0' && s1[i + 1] != '\0')
		i++;
	while (s1[i] && s2[j])
	{
		if ((s1[i] < s2[j]) || (s1[i] > s2[j]))
			return (1);
		i++;
		j++;
	}
	if (s1[i] || s2[j])
		return (1);
	return (0);
}

int	check_int_maxmin(int *array, char **str)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;

	i = 1;
	j = 0;
	k = 0;
	while (str[i])
	{
		tmp = ft_itoa(array[i - 1]);
		if (mod_strcmp(str[i], tmp) != 0)
		{
			free (tmp);
			return (write(2, "Error\n", 6));
		}
		i++;
		free (tmp);
	}
	return (0);
}
