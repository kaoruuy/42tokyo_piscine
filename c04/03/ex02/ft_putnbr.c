/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 08:01:22 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/17 21:40:35 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_nb_array(int *nb_array)
{
	int	i;
	int	len;
	char	num_str;

	i = 0;
	len = 0;
	while (nb_array[i])
	{
		i++;
		len++;
	}
	i = 0;
	while (i < len)
	{
		num_str = nb_array[len - i - 1] + '0';
		write(1, &num_str, 1);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	int	i;
	int	nb_array[64];

	i = 0;
	if (nb == 0)
		write(1, "0", 1);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
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
	ft_putnbr(0);
	return (0);
}
