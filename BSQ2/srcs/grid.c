/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:31:11 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/25 21:55:24 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bsq.h"

void	free_partial(char **grid, int r)
{
	while (r >= 0)
	{
		free(grid[r]);
		r--;
	}
	free(grid);
}

static int	fill_row(char *ptr, int len, int r, t_map *map)
{
	int	c;

	map->grid[r] = malloc(len + 1);
	if (!map->grid[r])
		return (0);
	c = 0;
	while (c < len)
	{
		if (ptr[c] != map->empty && ptr[c] != map->obstacle)
		{
			free(map->grid[r]);
			return (0);
		}
		map->grid[r][c] = ptr[c];
		c++;
	}
	map->grid[r][len] = '\0';
	return (1);
}

static char	*fill_grid(char *ptr, t_map *map)
{
	int	r;
	int	len;

	r = 0;
	while (r < map->rows)
	{
		len = 0;
		while (ptr[len] && ptr[len] != '\n')
			len++;
		if (r == 0)
			map->cols = len;
		if (len == 0 || len != map->cols || !fill_row(ptr, len, r, map))
			return (free_partial(map->grid, r - 1), NULL);
		ptr += len;
		if (*ptr != '\n')
			return (free_partial(map->grid, r), NULL);
		ptr++;
		r++;
	}
	return (ptr);
}

char	**build_grid(char *content, t_map *map)
{
	char	*ptr;

	map->grid = malloc(sizeof(char *) * map->rows);
	if (!map->grid)
		return (NULL);
	ptr = content;
	while (*ptr && *ptr != '\n')
		ptr++;
	if (*ptr != '\n')
		return (free(map->grid), NULL);
	ptr = fill_grid(++ptr, map);
	if (!ptr || *ptr != '\0')
	{
		if (ptr)
			free_partial(map->grid, map->rows - 1);
		return (NULL);
	}
	return (map->grid);
}
