/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 22:45:32 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/18 10:10:44 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		return (0);
	while (i * i != nb)
		i++;
	if (i * i == nb)
		return (i);
	return (0);
}

// #include <stdio.h>

// int main()
// {
// 	printf("%d\n", ft_sqrt(25));
// 	printf("%d\n", ft_sqrt(1));
// 	printf("%d\n", ft_sqrt(0));
// 	printf("%d\n", ft_sqrt(-25));
// 	return (0);
// }
