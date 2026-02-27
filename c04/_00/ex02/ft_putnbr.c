/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 08:01:22 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/11 15:33:33 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>

int	count_length(int);
void	ft_putnbr(int);
void	print_nmb_array(int *, int);

// int	main(void)
// {
// 	ft_putnbr(10);
// 	return 0;
// }

void	ft_putnbr(int nb)
{
	int	i;
	int	length;
	int	number_array[64];

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
		number_array[i] = nb % 10;
		nb = nb / 10;
		i++;
	}
	print_nmb_array(number_array, length);
}

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

void	print_nmb_array(int *number_array, int length)
{
	int	i;
	char	num_str;
	
	i = length;
	while (i >= 0)
	{
		num_str = number_array[i] + '0';
		write(1, &num_str, 1);
		i--;
	}
}
