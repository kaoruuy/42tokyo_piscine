/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 20:57:23 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/15 20:25:47 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	is_valid_num(int *current_array, int size, int num)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (current_array[i] == num)
			return (0);
		i++;
	}
	return (1);
}

void	perm_recursive(int perms[MAX_CANDS][N], int *current_array, int *count,
		int size)
{
	int	i;
	int	num;

	if (size == N)
	{
		i = 0;
		while (i < N)
		{
			perms[*count][i] = current_array[i];
			i++;
		}
		(*count)++;
		return ;
	}
	num = 1;
	while (num <= N)
	{
		if (is_valid_num(current_array, size, num))
		{
			current_array[size] = num;
			perm_recursive(perms, current_array, count, size + 1);
		}
		num++;
	}
}

void	generate_all_perms_1to4(int perms[MAX_CANDS][N])
{
	int	current_array[N];
	int	count;

	count = 0;
	perm_recursive(perms, current_array, &count, 0);
}
