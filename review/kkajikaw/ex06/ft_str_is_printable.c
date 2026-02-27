/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 17:24:31 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/10 13:24:38 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= ' ' && str[i] <= '~'))
		{
			return (0);
		}
		else
		{
			i++;
		}
	}
	return (1);
}

#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_str_is_printable("Hello42"));
	printf("%d\n", ft_str_is_printable("Hello\n42"));
	printf("%d\n", ft_str_is_printable(""));
	return (0);
}
