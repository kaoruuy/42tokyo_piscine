/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 10:12:44 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/06 10:24:18 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

int main(void)
{
    int a;
    int b;
    int div;
    int mod;

    a = 10;
    b = 3;
    ft_div_mod(a, b, &div, &mod);
    printf("a = %d, b = %d\n", a, b);
    printf("div = %d\n", div);
    printf("mod = %d\n", mod);
    return 0;
}
