/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:53:53 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/11 09:58:27 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	while (s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}


// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	a[] = "text1";
// 	char	b[] = "text";
// 	char	*a_ptr;
// 	char	*b_ptr;

// 	a_ptr = a;
// 	b_ptr = b;
// 	printf("%d\n", ft_strcmp(a_ptr, b_ptr));
// 	printf("%d\n", strcmp(a_ptr, b_ptr));
// 	return (0);
// }

