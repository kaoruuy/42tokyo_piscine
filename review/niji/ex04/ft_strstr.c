/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 08:13:47 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/15 12:27:25 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		if (to_find[i] == '\0')
		{
			return (str);
		}
		j = 0;
		while (str[i] == to_find[j] && to_find[j] != '\0')
		{
			if (to_find[j] == '\0')
			{
				return (str + i);
			}
			j++;
		}
		i++;
	}
	return (0);
}

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	main(void)
{
	char	text[] = "tokyo42tokyo";
	char	target[] = "42";

	printf("%s", ft_strstr(text, target));
}
