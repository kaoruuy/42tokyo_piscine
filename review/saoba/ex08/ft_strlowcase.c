/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 17:57:38 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/12 17:28:52 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] - 'A' + 'a';
		}
		i++;
	}
	return (str);
}

#include <stdio.h>

int	main(void)
{
	char	a[] = "HELLO";
	char	b[] = "Hello42";
	printf("%s\n", ft_strlowcase(a));
	printf("%s\n", ft_strlowcase(b));
	return (0);
}
