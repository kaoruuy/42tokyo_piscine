/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:16:48 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/10 17:02:55 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

 #include <stdio.h>

int	main(void)
{
	int	i;
	int	int_array[] = {3,6,5,2,1,9,2};
	int	size;

	size = 7;
	printf("before: ");
	i = 0;
	while (i < size)
	{
		printf("%d ", int_array[i]);
		i++;
	}
	printf("\n");
	ft_sort_int_tab(int_array, 7);
	printf("after:  ");
	i = 0;
	while (i < size)
	{
		printf("%d ", int_array[i]);
		i++;
	}
	return 0;
} 
