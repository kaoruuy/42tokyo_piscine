/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 16:26:39 by komori            #+#    #+#             */
/*   Updated: 2026/02/22 21:10:36 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	print_unit_check(t_dict *dict, int magnitude)
{
	static char	*units[] = {"1000", "1000000", "1000000000", "1000000000000",
		"1000000000000000", "1000000000000000000", "1000000000000000000000",
		"1000000000000000000000000", "1000000000000000000000000000",
		"1000000000000000000000000000000",
		"1000000000000000000000000000000000",
		"1000000000000000000000000000000000000"};

	if (magnitude < 1 || magnitude > 12)
		return (1);
	if (find_in_dict(dict, units[magnitude - 1]) == 0)
		return (0);
	return (1);
}

int	check_3_digits(t_dict *dict, char *str)
{
	int		len;
	char	tmp[3];

	len = ft_strlen(str);
	if (len == 3 && str[0] != '0')
	{
		tmp[0] = str[0];
		tmp[1] = '\0';
		if (!find_in_dict(dict, tmp) || !find_in_dict(dict, "100"))
			return (0);
	}
	if (len >= 2 && str[len - 2] == '1')
		return (find_in_dict(dict, &str[len - 2]) != 0);
	if (len >= 2 && str[len - 2] != '0')
	{
		tmp[0] = str[len - 2];
		tmp[1] = '0';
		tmp[2] = '\0';
		if (!find_in_dict(dict, tmp))
			return (0);
	}
	tmp[0] = str[len - 1];
	tmp[1] = '\0';
	return (str[len - 1] == '0' || find_in_dict(dict, tmp) != 0);
}

int	check_number(t_dict *dict, char *number)
{
	int		len;
	int		mag;
	int		f_len;
	char	*f;

	len = ft_strlen(number);
	if (len <= 3)
		return (check_3_digits(dict, number));
	mag = (len - 1) / 3;
	f_len = len - mag * 3;
	f = ft_strndup(number, f_len);
	if (!f)
		return (0);
	len = check_3_digits(dict, f);
	free(f);
	if (!len || !print_unit_check(dict, mag))
		return (0);
	number += f_len;
	while (*number == '0')
		number++;
	if (*number)
		return (check_number(dict, number));
	return (1);
}
