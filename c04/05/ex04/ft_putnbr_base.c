/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:26:02 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/22 21:51:11 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_valid(char *base)
{
	int	i;
	int	j;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] == 127)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	count_base(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

void	ft_put_recursive(long n, char *base, int base_len)
{
	if (n >= base_len)
		ft_put_recursive(n / base_len, base, base_len);
	write(1, &base[n % base_len], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	n;
	int		base_len;

	if (!is_valid(base))
		return ;
	base_len = count_base(base);
	n = nbr;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	ft_put_recursive(n, base, base_len);
}

// #include <stdio.h>

// int main()
// {
// 	ft_putnbr_base(4, "01");
// 	printf("\n");
// 	ft_putnbr_base(-16, "01");
// 	printf("\n");
// 	ft_putnbr_base(-100, "0123456789ABCDEF");
// 	printf("\n");
// 	ft_putnbr_base(-2147483648, "0123456789ABCDEF");
// 	return (0);
// }
