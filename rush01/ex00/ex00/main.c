/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:02:53 by sokabaya          #+#    #+#             */
/*   Updated: 2026/02/15 21:03:38 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_grid(int grid[N][N]);

int	parse_clues(char *argv, int *array)
{
	int	n;
	int	nb;
	int	i;

	n = 0;
	i = 0;
	while (argv[n])
	{
		if (argv[n] >= '1' && argv[n] <= N_CHR)
		{
			nb = argv[n] - '0';
			array[i] = nb;
			n++;
			i++;
		}
		else if ((argv[n] >= 1 && argv[n] <= 13) || argv[n] == 32)
			n++;
		else
			return (0);
	}
	if (i == N * N)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int	grid[N][N];
	int	perms[MAX_CANDS][N];
	int	row_candidates[N][MAX_CANDS][N];
	int	r;
	int	array[N * N];

	if (argc != 2 || !parse_clues(argv[1], array))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	generate_all_perms_1to4(perms);
	r = 0;
	while (r < N)
	{
		filter_row_candidates(row_candidates[r], perms, array[N * 2 + r],
			array[N * 3 + r]);
		r++;
	}
	if (solve_by_rows(0, grid, row_candidates, array))
		print_grid(grid);
	else
		write(1, "Error\n", 6);
	return (0);
}
