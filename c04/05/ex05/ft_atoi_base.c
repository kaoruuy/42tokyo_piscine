/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 16:40:55 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/23 16:19:52 by kayoshid         ###   ########.fr       */
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
	return (i);
}

int	count_base(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	get_decimal(char c, char *base, int base_len)
{
	int	i;

	i = 0;
	while (i < base_len)
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	get_sign(char **str)
{
	int	sign;

	sign = 1;
	while (**str == 32 || (**str >= 9 && **str <= 13))
		(*str)++;
	while (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = sign * (-1);
		(*str)++;
	}
	return (sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	ans;
	int	sign;
	int	base_len;
	int	val;

	if (!is_valid(base))
		return (0);
	base_len = count_base(base);
	if (base_len < 2)
		return (0);
	ans = 0;
	sign = get_sign(&str);
	while (*str)
	{
		val = get_decimal(*str, base, base_len);
		if (val == -1)
			break ;
		ans = ans * base_len + val;
		str++;
	}
	return (ans * sign);
}

#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_atoi_base("    -+--1000", "01"));
	printf("%d\n", ft_atoi_base("   --64", "0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("-2147483648", "0123456789ABCDEF"));
	return (0);
}
