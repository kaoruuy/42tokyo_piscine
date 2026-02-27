/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 06:55:53 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/08 15:20:29 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAX_LINE 10280

void	ft_putchar(char c);

void	print_char(int x, int y, int col, int row)
{
	if ((row == 1 && col == 1) || (row == y && col == x))
		ft_putchar('A');
	else if ((row == 1 && col == x) || (row == y && col == 1))
		ft_putchar('C');
	else if (row == 1 || row == y || col == 1 || col == x)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	row;
	int	col;

	if (x <= 0 || x > MAX_LINE || y <= 0 || y > MAX_LINE)
		return ;
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
