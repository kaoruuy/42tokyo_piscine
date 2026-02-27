/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 17:12:48 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/10 14:24:32 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
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
	printf("%d\n", ft_str_is_numeric("42"));
	printf("%d\n", ft_str_is_numeric("Hello42"));
	printf("%d\n", ft_str_is_numeric(""));
	return (0);
} 
