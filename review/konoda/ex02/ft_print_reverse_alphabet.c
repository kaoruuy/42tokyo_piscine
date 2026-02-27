/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:00:24 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/06 11:14:13 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	int		i;
	char	str;

	i = 0;
	str = 'z';
	while (i < 26)
	{
		write(1, &str, 1);
		str--;
		i++;
	}
}

int main()
{
	ft_print_reverse_alphabet();
	return 0;
}