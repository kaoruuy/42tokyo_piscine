
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 15:13:44 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/05 15:14:44 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void ft_print_alphabet(void)
{
    int  i;
    char str;

    i = 0;
    str = 'a';
    while (i < 26)
    {
        write(1, &str, 1);
        str++;
        i++;
    }
}

int main(void)
{
	ft_print_alphabet();
	write(1, "\n", 1);
	return 0;
}