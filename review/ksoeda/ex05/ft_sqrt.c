/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 22:45:32 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/18 08:10:32 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while (i * i != nb && i < nb / 2)
		i++;
	if (i * i == nb)
		return (i);
	return (0);
}

#include <stdio.h>

int main()
{
	printf("%d\n", ft_sqrt(35));
	return (0);
}
