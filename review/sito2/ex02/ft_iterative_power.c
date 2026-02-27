/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 21:47:51 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/19 07:46:58 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	ans;

	i = 0;
	ans = 1;
	if (nb == 0 && power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (i < power)
	{
		ans *= nb;
		i++;
	}
	return (ans);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", ft_iterative_power(3, 3));
// 	printf("%d\n", ft_iterative_power(3, 0));
// 	printf("%d\n", ft_iterative_power(0, 0));
// 	return (0);
// }
