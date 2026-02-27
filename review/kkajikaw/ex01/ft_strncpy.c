/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:13:13 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/10 13:18:44 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	count;

	count = 0;
	while (count < n)
	{
		dest[count] = src[count];
		count++;
	}
	while (dest[count] != '\0')
	{
		dest[count] = '\0';
		count++;
	}
	src[count] = '\0';
	return (dest);
}

#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	destination[64] = "12345";
	char	source[64] = "1234567890";
	
	printf("%s\n", ft_strncpy(destination, source, 10));
	printf("%s\n", strncpy(destination, source, 10));
} 
