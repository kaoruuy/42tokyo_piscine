/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:31:22 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/25 21:17:24 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>

static int	parse_header(char *line, t_map *map)
{
	int	i;
	int	len;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	if (len < 4 || line[len] != '\n')
		return (0);
	map->full = line[len - 1];
	map->obstacle = line[len - 2];
	map->empty = line[len - 3];
	i = 0;
	map->rows = 0;
	while (i < len - 3)
	{
		if (!ft_isdigit(line[i]))
			return (0);
		map->rows = map->rows * 10 + (line[i++] - '0');
	}
	if (map->rows <= 0 || map->empty == map->obstacle || map->empty == map->full
		|| map->obstacle == map->full)
		return (0);
	return (is_printable(map->empty) && is_printable(map->obstacle)
		&& is_printable(map->full));
}

t_map	*parse_map(char *content)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	if (!parse_header(content, map))
	{
		free(map);
		return (NULL);
	}
	map->grid = build_grid(content, map);
	if (!map->grid)
	{
		free(map);
		return (NULL);
	}
	map->dp = NULL;
	return (map);
}

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->grid)
	{
		i = 0;
		while (i < map->rows)
			free(map->grid[i++]);
		free(map->grid);
	}
	if (map->dp)
	{
		i = 0;
		while (i < map->rows)
			free(map->dp[i++]);
		free(map->dp);
	}
	free(map);
}
