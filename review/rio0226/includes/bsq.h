/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:31:08 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/25 20:47:28 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

typedef struct s_map
{
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
	char	**grid;
	int		**dp;
}			t_map;

char		*read_file(int fd);
t_map		*parse_map(char *content);
void		free_map(t_map *map);
char		**build_grid(char *content, t_map *map);
void		free_partial(char **grid, int r);
int			solve(t_map *map);
void		print_map(t_map *map);

int			ft_isdigit(char c);
int			is_printable(char c);

#endif
