/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 09:14:09 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/27 08:39:44 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_alphanumeric(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

void	ft_strupcase(char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 'a' + 'A';
}

void	ft_strlowcase(char *c)
{
	if (*c >= 'A' && *c <= 'Z')
		*c = *c - 'A' + 'a';
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_is_alphanumeric(str[i]) == 1)
		{
			if (ft_is_alphanumeric(str[i - 1]) == 1)
				ft_strupcase(&str[i]);
			else
				ft_strlowcase(&str[i]);
		}
		i++;
	}
	return (str);
}

int	main(void)
{
	char	a[] = "hi, how are you? 42words forty-two; fifty+and+one";
	printf("%s\n", ft_strcapitalize(a));
	return (0);
}
