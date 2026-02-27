/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 06:55:53 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/07 14:54:44 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c);

void	print_char(int x, int y, int col, int row)
{
	if (row == 1 || row == y)
	{
		if (col == 1 || col == x)
			ft_putchar('o');
		else
			ft_putchar('-');
	}
	else
	{
		if (col == 1 || col == x)
			ft_putchar('|');
		else
			ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int		row;
	int		col;

	if (x <= 0 || y <= 0)
	{
		return ;
	}
	row = 1;
	while (row <= y)
	{
		col = 1;
		while (col <= x)
		{
			print_char(x, y, col, row);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
