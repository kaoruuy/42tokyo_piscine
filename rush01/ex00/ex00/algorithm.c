/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 14:19:34 by kkomurat          #+#    #+#             */
/*   Updated: 2026/02/15 21:06:12 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	cnt(int grid[N][N], int c, int is_down)
{
	int	r;
	int	max;
	int	count;

	count = 0;
	max = 0;
	r = 0;
	if (is_down)
		r = N - 1;
	while (r >= 0 && r < N)
	{
		if (grid[r][c] > max)
		{
			max = grid[r][c];
			count++;
		}
		if (is_down)
			r--;
		else
			r++;
	}
	return (count);
}

int	check_cols(int grid[N][N], int constraints[N * N])
{
	int	c;

	c = 0;
	while (c < N)
	{
		if (cnt(grid, c, 0) != constraints[c])
			return (0);
		if (cnt(grid, c, 1) != constraints[c + N])
			return (0);
		c++;
	}
	return (1);
}

int	can_put(int r, int grid[N][N], int cand[N])
{
	int	c;
	int	rr;

	c = 0;
	while (c < N)
	{
		rr = 0;
		while (rr < r)
		{
			if (grid[rr][c] == cand[c])
				return (0);
			rr++;
		}
		c++;
	}
	return (1);
}

void	set(int r, int grid[N][N], int cand[N], int undo)
{
	int	c;

	c = 0;
	while (c < N)
	{
		if (undo)
			grid[r][c] = 0;
		else
			grid[r][c] = cand[c];
		c++;
	}
}

int	solve_by_rows(int r, int grid[N][N], int row_cands[N][MAX_CANDS][N],
		int cons[N * N])
{
	int	i;

	if (r == N)
		return (check_cols(grid, cons));
	i = 0;
	while (row_cands[r][i][0] != 0)
	{
		if (can_put(r, grid, row_cands[r][i]))
		{
			set(r, grid, row_cands[r][i], 0);
			if (solve_by_rows(r + 1, grid, row_cands, cons))
				return (1);
			set(r, grid, 0, 1);
		}
		i++;
	}
	return (0);
}
