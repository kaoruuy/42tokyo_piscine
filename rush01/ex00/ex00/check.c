/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 15:00:18 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/15 20:56:35 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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

int	visible_count(int *array, int size, int is_reverse)
{
	int	i;
	int	intmax;
	int	count;
	int	current_val;

	i = 0;
	intmax = 0;
	count = 0;
	while (i < size)
	{
		if (is_reverse == 1)
			current_val = array[size - 1 - i];
		else
			current_val = array[i];
		if (current_val > intmax)
		{
			intmax = current_val;
			count++;
		}
		i++;
	}
	return (count);
}

bool	visible_partial_feasible(int *array_not_enough, int size, int target)
{
	int	current_visible;

	current_visible = visible_count(array_not_enough, size, 0);
	if (current_visible > target || current_visible + N - size < target)
	{
		return (false);
	}
	else
	{
		return (true);
	}
}

int	filter_row_candidates(int row_candidates[MAX_CANDS][N], int perms[][N],
		int left_target, int right_target)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (i < MAX_CANDS)
	{
		if (visible_count(perms[i], N, 0) == left_target
			&& visible_count(perms[i], N, 1) == right_target)
		{
			k = 0;
			while (k < N)
			{
				row_candidates[j][k] = perms[i][k];
				k++;
			}
			j++;
		}
		i++;
	}
	return (j);
}
