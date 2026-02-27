/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:31:29 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/25 10:31:30 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bsq.h"

static int	alloc_dp(t_map *map)
{
	int	r;

	map->dp = malloc(sizeof(int *) * map->rows);
	if (!map->dp)
		return (0);
	r = 0;
	while (r < map->rows)
	{
		map->dp[r] = malloc(sizeof(int) * map->cols);
		if (!map->dp[r])
			return (0);
		r++;
	}
	return (1);
}

static void	fill_square(t_map *map, int best_r, int best_c, int size)
{
	int	r;
	int	c;

	r = best_r - size + 1;
	while (r <= best_r)
	{
		c = best_c - size + 1;
		while (c <= best_c)
		{
			map->grid[r][c] = map->full;
			c++;
		}
		r++;
	}
}

static int	calc_dp(t_map *map, int r, int c)
{
	int	a;
	int	b;
	int	d;

	if (map->grid[r][c] == map->obstacle)
		return (0);
	if (r == 0 || c == 0)
		return (1);
	a = map->dp[r - 1][c];
	b = map->dp[r][c - 1];
	d = map->dp[r - 1][c - 1];
	if (a < b && a < d)
		return (a + 1);
	if (b < d)
		return (b + 1);
	return (d + 1);
}

static void	run_dp(t_map *map, int r, int *best)
{
	int	c;

	c = 0;
	while (c < map->cols)
	{
		map->dp[r][c] = calc_dp(map, r, c);
		if (map->dp[r][c] > best[0])
		{
			best[0] = map->dp[r][c];
			best[1] = r;
			best[2] = c;
		}
		c++;
	}
}

int	solve(t_map *map)
{
	int	r;
	int	best[3];

	if (!alloc_dp(map))
		return (0);
	best[0] = 0;
	best[1] = 0;
	best[2] = 0;
	r = 0;
	while (r < map->rows)
	{
		run_dp(map, r, best);
		r++;
	}
	fill_square(map, best[1], best[2], best[0]);
	return (1);
}
