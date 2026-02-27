/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:58:03 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/05 19:05:56 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void print_reverse_alphabet(void)
{
	int	i;
	char	c;
	
	i = 0;
	c = 'z';
	while (i < 26)
	{
		write(1, &c, 1);
		i++;
		c--;
	}
}

int main()
{
	print_reverse_alphabet();
	return 0;
}
