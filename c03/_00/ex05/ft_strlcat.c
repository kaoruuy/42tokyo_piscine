/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:41:06 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/11 10:18:49 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (j < size - i){
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (i + j);
}

#include <stdio.h>

int	main(void)
{
	char	a[] = "hoge";
	char	b[] = "fuga";

	printf("ft_strlcat(a, b, 4) = %d\n", ft_strlcat(a, b, 4));
	printf("a = %s\n", a);
	return (0);
}
