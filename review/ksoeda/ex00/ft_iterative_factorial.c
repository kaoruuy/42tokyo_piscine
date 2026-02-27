/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 21:17:01 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/18 08:03:30 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	ans;

	i = 1;
	ans = 1;
	if (nb <= 0)
		return (0);
	while (i <= nb)
	{
		ans *= i;
		i++;
	}
	return (ans);
}

int	main(void)
{
	printf("%d", ft_iterative_factorial(0));
	return (0);
}
