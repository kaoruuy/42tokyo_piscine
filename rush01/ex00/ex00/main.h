/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 15:00:47 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/15 21:08:26 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#define N 4
#define N_CHR '4'
#define MAX_CANDS 24

void	ft_rev_int_tab(int *tab, int size);
int		visible_count(int *array, int size, int is_reverse);
bool	visible_partial_feasible(int *array_not_enough, int size, int target);
int		filter_row_candidates(int row_candidates[MAX_CANDS][N], int perms[][N],
			int left_target, int right_target);

int		solve_by_rows(int r, int grid[N][N],
			int row_candidates[N][MAX_CANDS][N], int constraints[N * N]);
int		cnt(int grid[N][N], int c, int is_down);
int		check_cols(int grid[N][N], int constraints[N * N]);
int		can_put(int r, int grid[N][N], int cand[N]);
void	set(int r, int grid[N][N], int cand[N], int undo);

void	print_grid(int grid[N][N]);

int		is_valid_num(int *current_array, int size, int num);
void	perm_recursive(int perms[MAX_CANDS][N], int *current_array, int *count,
			int size);
void	generate_all_perms_1to4(int perms[MAX_CANDS][N]);
