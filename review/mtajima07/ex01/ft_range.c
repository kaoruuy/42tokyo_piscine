/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:27:17 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/18 07:25:24 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	num;
	int	*dest;

	if (min >= max)
		return (0);
	i = 0;
	num = max - min;
	dest = (int *)malloc(sizeof(int) * (num + 1));
	if (dest == NULL)
		return (0);
	i = 0;
	while (i < num)
	{
		dest[i] = min + i;
		i++;
	}
	return (dest);
}

// #include <unistd.h>

// int	main(void)
// {
// 	int		*test;
// 	int		i;
// 	int		min;
// 	int		max;
// 	char	c;

// 	min = 3;
// 	max = 7;
// 	i = 0;
// 	test = ft_range(min, max);
// 	while (test[i])
// 	{
// 		c = test[i] + '0';
// 		write(1, &c, 1);
// 		if (i < max - min - 1)
// 			write(1, ", ", 1);
// 		i++;
// 	}
// 	free(test);
// 	return (0);
// }
