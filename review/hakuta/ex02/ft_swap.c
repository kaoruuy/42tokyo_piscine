/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 09:24:27 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/09 16:25:34 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a,	int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

// /*
#include <stdio.h>

int	main(void)
{
	int	x;
	int	y;

	x = 10;
	y = 20;

	ft_swap(&x, &y);
	printf("x = %d, y = %d\n", x, y);

	return (0);
} 
