/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 08:13:47 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/11 09:59:12 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			while (str[i + j] == to_find[j] && to_find[j] != '\0')
			{
				j++;
			}
			if (to_find[j] == '\0')
			{
				return (str + i);
			}
			i++;
		}
		else
		{
			i++;
		}
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// #include <unistd.h>

// int	main(void)
// {
// 	char	text[] = "4242tokyo";
// 	char	target[] = "42";

// 	printf("%s", ft_strstr(text, target));
// }
