/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:25:46 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/11 21:30:26 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

// int	ft_atoi(char *);
// int	ft_isspace(int);

// int	main(void)
// {
// 	char	a[] = " ---+--+1234ab567";
// 	printf("%d", ft_atoi(a));
//	return 0;
// }

int	ft_atoi(char *str)
{
	int	i;
	int	m;
	int	ans;

	i = 0;
	m = 1;
	ans = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			m = m * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ans = ans * 10 + str[i] - '0';
		i++;
	}
	return (ans);
}

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
