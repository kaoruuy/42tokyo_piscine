/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 07:05:52 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/08 14:52:27 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_ft(int *****nbr)
{
	*****nbr = 42;
}
#include <stdio.h>
int	main(void)
{
	int		n;
	int		*p1;
	int		**p2;
	int		***p3;
	int		****p4;
	int		*****p5;

	n = 0;

	p1 = &n;
	p2 = &p1;
	p3 = &p2;
	p4 = &p3;
	p5 = &p4;

	ft_ultimate_ft(p5);
	printf("%d\n", n);

	return (0);
}