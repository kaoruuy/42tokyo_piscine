/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:31:14 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/25 20:55:43 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

static void	process(int fd, int print_newline)
{
	char	*content;
	t_map	*map;

	if (print_newline)
		write(1, "\n", 1);
	content = read_file(fd);
	if (!content)
	{
		write(1, "map error\n", 10);
		return ;
	}
	map = parse_map(content);
	free(content);
	if (!map || !solve(map))
	{
		write(1, "map error\n", 10);
		free_map(map);
		return ;
	}
	print_map(map);
	free_map(map);
}

int	main(int argc, char **argv)
{
	int	fd;
	int	i;
	int	first_done;

	if (argc == 1)
		return (process(0, 0), 0);
	i = 1;
	first_done = 0;
	while (i < argc)
	{
		if (first_done)
			write(1, "\n", 1);
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
			write(1, "map error\n", 10);
		else
		{
			process(fd, 0);
			close(fd);
		}
		first_done = 1;
		i++;
	}
	return (0);
}
