/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 16:12:29 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/23 10:32:18 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_valid(char *base);
int		ft_atoi_base(char *str, char *base);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	get_len(long n, int base_len)
{
	int	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

void	ft_put_recursive(long n, char *base_to, int base_to_len, char **ptr)
{
	if (n >= base_to_len)
		ft_put_recursive(n / base_to_len, base_to, base_to_len, ptr);
	**ptr = base_to[n % base_to_len];
	(*ptr)++;
}

char	*ft_itoa_base(int nbr, char *base_to)
{
	long	ln;
	int		base_to_len;
	char	*ans;
	char	*ptr;

	base_to_len = ft_strlen(base_to);
	ln = nbr;
	ans = (char *)malloc(sizeof(char) * (get_len(ln, base_to_len) + 1));
	if (ans == NULL)
		return (NULL);
	ptr = ans;
	if (ln == 0)
		*ptr++ = base_to[0];
	else
	{
		if (ln < 0)
		{
			*ptr++ = '-';
			ln = -ln;
		}
		ft_put_recursive(ln, base_to, base_to_len, &ptr);
	}
	*ptr = '\0';
	return (ans);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	char	*ans;

	if (!is_valid(base_from) || !is_valid(base_to))
		return (NULL);
	num = ft_atoi_base(nbr, base_from);
	ans = ft_itoa_base(num, base_to);
	return (ans);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%s\n", ft_convert_base("100", "0123456789", "0123456789ABCDEF"));
// 	printf("%s\n", ft_convert_base("-10", "0123456789ABCDEF", "01"));
// 	return (0);
// }