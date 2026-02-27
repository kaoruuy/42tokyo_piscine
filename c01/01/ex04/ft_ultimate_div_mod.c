/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 10:25:50 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/08 11:33:22 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

#include <stdio.h>
int	main(void)
{
	int	a;
	int	b;

	a = 17;
	b = 5;

	ft_ultimate_div_mod(&a, &b);
	printf("a = %d, b = %d\n", a, b);

	return (0);
}