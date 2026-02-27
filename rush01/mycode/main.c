/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 09:53:15 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/14 15:53:56 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// 上からor下からを逆転させる関数
void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = tab[size - i - 1];
		tab[size - i - 1] = tab[i];
		tab[i] = tmp;
		i++;
	}
}

int	visible_count(int *array, int size)
{
	int	i;
	int	intmax;
	int	count;

	i = 0;
	intmax = 0;
	count = 0;
	while (i < size)
	{
		if (array[i] > intmax)
		{
			intmax = array[i];
			count++;
		}
		i++;
	}
	return (count);
}

bool	visible_partial_feasible(int *array_not_enough, int size, int target, int direction)
{
	int	current_visible;

	current_visible = visible_count(array_not_enough, size);
	if (current_visible > target | current_visible + 4 - size < target)
		return (false);
}

int	main(int argc, char *argv[])
{
	int a[] = {2, 3, 4, 1};
	printf("%d\n", visible_count(a));
}
