/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_in_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komori <komori@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 18:03:30 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/22 16:58:49 by komori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*find_in_dict(t_dict *dict, char *number)
{
	int	i;

	i = 0;
	while (dict[i].key != NULL)
	{
		if (ft_strcmp(dict[i].key, number) == 0)
			return (dict[i].value);
		i++;
	}
	return (0);
}

int	print_unit(t_dict *dict, int magnitude)
{
	static char	*units[] = {"1000", "1000000", "1000000000", "1000000000000",
		"1000000000000000", "1000000000000000000", "1000000000000000000000",
		"1000000000000000000000000", "1000000000000000000000000000",
		"1000000000000000000000000000000",
		"1000000000000000000000000000000000",
		"1000000000000000000000000000000000000"};
	char		*unit_word;

	if (magnitude < 1 || magnitude > 12)
		return (1);
	unit_word = find_in_dict(dict, units[magnitude - 1]);
	if (unit_word == 0)
		return (0);
	write(1, " ", 1);
	ft_putstr(unit_word);
	return (1);
}
