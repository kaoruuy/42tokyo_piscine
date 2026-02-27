/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_us_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:26:07 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/05 20:31:25 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_is_negative(int n)
{
	char	str_n;
	char	str_p;

	str_n = 'N';
	str_p = 'P';
	if (n < 0)
	{
		write(1, &str_n, 1);
	}
	else
	{
		write(1, &str_p, 1);
	}
}
