/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:24:48 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/10 13:20:58 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z')))
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
	printf("%d\n", ft_str_is_alpha("@[`{}]"));
	printf("%d\n", ft_str_is_alpha("aAzZ"));
	printf("%d\n", ft_str_is_alpha(""));
	return (0);
}
