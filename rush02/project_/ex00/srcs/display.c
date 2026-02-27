/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komori <komori@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 18:06:13 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/22 17:00:07 by komori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	print_1_digit(t_dict *dict, char c)
{
	char	tmp[2];
	char	*str;

	tmp[0] = c;
	tmp[1] = '\0';
	str = find_in_dict(dict, tmp);
	if (!str)
		return (0);
	ft_putstr(str);
	return (1);
}

int	print_2_digits(t_dict *dict, char *str)
{
	char	tmp[3];
	char	*res;

	if (str[0] == '1')
	{
		res = find_in_dict(dict, str);
		if (!res)
			return (0);
		return (ft_putstr(res), 1);
	}
	if (str[0] != '0')
	{
		tmp[0] = str[0];
		tmp[1] = '0';
		tmp[2] = '\0';
		res = find_in_dict(dict, tmp);
		if (!res)
			return (0);
		ft_putstr(res);
		if (str[1] != '0' && write(1, " ", 1))
			return (print_1_digit(dict, str[1]));
	}
	else if (str[1] != '0')
		return (print_1_digit(dict, str[1]));
	return (1);
}

int	print_3_digits(t_dict *dict, char *str)
{
	int		len;
	char	*h;

	len = ft_strlen(str);
	if (len == 3 && str[0] != '0')
	{
		h = find_in_dict(dict, "100");
		if (!h || !print_1_digit(dict, str[0]))
			return (0);
		write(1, " ", 1);
		ft_putstr(h);
		if (str[1] != '0' || str[2] != '0')
			write(1, " ", 1);
	}
	if (len == 3)
		return (print_2_digits(dict, &str[1]));
	if (len == 2)
		return (print_2_digits(dict, str));
	if (len == 1 && str[0] != '0')
		return (print_1_digit(dict, str[0]));
	return (1);
}

int	print_rest(t_dict *dict, char *number, int magnitude)
{
	int	i;

	if (!print_unit(dict, magnitude))
		return (0);
	i = 0;
	while (number[i] == '0')
		i++;
	if (number[i])
	{
		write(1, " ", 1);
		if (!print_number(dict, &number[i]))
			return (0);
	}
	return (1);
}

int	print_number(t_dict *dict, char *number)
{
	int		len;
	int		mag;
	int		f_len;
	char	*f;
	int		res;

	len = ft_strlen(number);
	if (len <= 3)
		return (print_3_digits(dict, number));
	mag = (len - 1) / 3;
	f_len = len - mag * 3;
	f = ft_strndup(number, f_len);
	if (!f)
		return (0);
	res = print_3_digits(dict, f);
	free(f);
	if (!res || !print_rest(dict, number + f_len, mag))
		return (0);
	return (1);
}
