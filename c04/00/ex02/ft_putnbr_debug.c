/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 08:01:22 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/11 09:16:54 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	count_length(int);
void	ft_putnbr(int);
void	print_nmb_array(char *, int);

int	main(void)
{
	ft_putnbr(42);
	return 0;
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
	printf("length = %d\n", i);
	return (i);
}

void	ft_putnbr(int nb)
{
	int	i;
	int	length;
	int	div;
	char	test_str;
	// char	*number_array;
	// char	nb_to_print;

	i = 0;
	length = count_length(nb);
	div = 0;
	while (i <= length)
	{
		div = nb % 10;
		printf("ft_putchar: div=%d, length-i=%d", div, length-i);
		test_str = div+'0';
		printf("test_str=%d\n", test_str);
		// print_nmb_array(number_array, length);
		// nb_to_print = div + '0';
		// write(1, &nb_to_print, 1);
		nb = nb / 10;
		i++;
	}
}

// void	print_nmb_array(char *number_array, int length)
// {
// 	int	i;
// 	while (i < length)
// 	{
// 		write(1, &number_array[i], 1);
// 		i++;
// 	}
// }
