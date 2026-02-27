/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 18:11:48 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/12 11:27:42 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;

	i = 0;
	while (i < nb && src[i] != '\0')
	{
		dest[nb + i] = src[i];
		i++;
	}
	dest[nb + i] = '\0';
	return (dest);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	a[] = "hoge";
	char	b[] = "fuga";

	printf("%s\n", ft_strncat(a, b, 5));
	// printf("%s\n", strncat(a, b, 5));
	return (0);
}
