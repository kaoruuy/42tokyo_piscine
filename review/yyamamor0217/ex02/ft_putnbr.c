/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 08:01:22 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/17 13:16:32 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_nb_array(int *nb_array)
{
	char	num_str;

	while (*nb_array)
	{
		num_str = *nb_array + '0';
		write(1, &num_str, 1);
		nb_array++;
	}
}

void	ft_putnbr(int nb)
{
	int	i;
	int	nb_array[64];

	i = 0;
	while (nb)
	{
		nb_array[i] = nb % 10;
		nb = nb / 10;
		i++;
	}
	nb_array[i] = '\0';
	print_nb_array(nb_array);
}

#include <unistd.h>

int	main(void)
{
	ft_putnbr(-1);
	return (0);
}
