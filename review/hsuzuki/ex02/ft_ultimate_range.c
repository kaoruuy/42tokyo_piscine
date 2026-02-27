/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 07:25:15 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/23 11:41:37 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int *range[], int min, int max)
{
	int	i;
	int	size;
	int	*a;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	a = (int *)malloc(sizeof(int) * (size + 1));
	if (a == NULL)
		return (-1);
	i = 0;
	while (i < size)
	{
		a[i] = min + i;
		i++;
	}
	*range = a;
	return (size);
}

int	main(void)
{
	int	*test;
	int	size;

	size = ft_ultimate_range(&test, 3, 7);
	printf("size: %d\n", size);
	printf("1st index of test: %d\n", *test);
	free(test);
	return (0);
}
