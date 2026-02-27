/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:39:47 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/11 09:58:38 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
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
// 	printf("%d\n", ft_strncmp(a_ptr, b_ptr, 4));
// 	printf("%d\n", strncmp(a_ptr, b_ptr, 4));
// 	return (0);
// }
