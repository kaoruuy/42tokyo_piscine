/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 10:20:28 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/10 17:01:42 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = tab[size - i - 1];
		tab[size - i - 1] = tab[i];
		tab[i] = tmp;
		i++;
	}
}

#include <stdio.h>

int	main(void)
{
	int	i;
	int	int_array[] = {3,6,5,2,1};
	int	size;

	size = 5;
	printf("before: ");
	i = 0;
	while (i < size)
	{
		printf("%d ", int_array[i]);
		i++;
	}
	printf("\n");
	ft_rev_int_tab(int_array, 5);
	printf("after:  ");
	i = 0;
	while (i < size)
	{
		printf("%d ", int_array[i]);
		i++;
	}
	return 0;
}
