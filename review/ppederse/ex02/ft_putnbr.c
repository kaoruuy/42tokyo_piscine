/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 08:01:22 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/16 13:28:31 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	count_length(int nb)
{
	int	i;

	i = 0;
	while (nb / 10 != 0)
	{
		nb = nb % 10;
		i++;
	}
	return (i);
}

void	print_nb_array(int *nb_array, int length)
{
	int		i;
	char	num_str;

	i = length;
	while (i >= 0)
	{
		num_str = nb_array[i] + '0';
		write(1, &num_str, 1);
		i--;
	}
}

void	ft_putnbr(int nb)
{
	int	i;
	int	length;
	int	nb_array[64];

	i = 0;
	if (nb >= 0)
	{
		length = count_length(nb);
	}
	else
	{
		write(1, "-", 1);
		nb = -nb;
		length = count_length(nb);
	}
	while (i <= length)
	{
		nb_array[i] = nb % 10;
		nb = nb / 10;
		i++;
	}
	print_nb_array(nb_array, length);
}

#include <unistd.h>

int	main(void)
{
	ft_putnbr(110);
	return (0);
}
