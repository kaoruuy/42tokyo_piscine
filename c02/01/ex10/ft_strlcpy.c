/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 09:39:44 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/09 11:49:19 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// できてない！！

unsigned int	*ft_strlcpy(char *dest, char *src, unsigned int n)
{
	int	i;
	int	count;

	i = 0;
	while (i < n - 1)
	{
		dest[i] = src[i];
		i++;
		count++;
	}
	while (dest[i] != '\0')
	{
		dest[i] = '\0';
		i++;
	}
	src[i] = '\0';
	return ((unsigned int *)count);
}

/* #include <string.h>
#include <stdio.h>

int	main(void)
{
	char	destination[] = "destination";
	char	source[] = "source";
	
	printf("%d\n", ft_strlcpy(destination, source, 6));
	printf("%d\n", strlcpy(destination, source, 6));
} */
