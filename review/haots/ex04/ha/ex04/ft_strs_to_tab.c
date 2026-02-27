/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:46:44 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/24 08:03:19 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"

char	*get_copy(char *str, int size)
{
	char	*copy;
	int		i;

	copy = (char *)malloc(sizeof(char) * (size + 1));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	int			j;
	t_stock_str	*tab;

	i = 0;
	tab = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (tab == NULL)
		return (NULL);
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
			j++;
		tab[i].size = j;
		tab[i].str = av[i];
		tab[i].copy = get_copy(av[i], j);
		i++;
	}
	tab[i].str = 0;
	return (tab);
}

// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	t_stock_str	*tab;
// 	int	i;

// 	tab = ft_strs_to_tab(argc, argv);
// 	if (tab == NULL)
// 		return (1);
// 	i = 0;
// 	while(tab[i].str)
// 	{
// 		printf("--- index %d ---\n", i);
// 		printf("size: %d\n", tab[i].size);
// 		printf("str: %s\n", tab[i].str);
// 		printf("copy: %s\n\n", tab[i].copy);
// 		i++;
// 	}
// 	i = 0;
// 	while (tab[i].str)
// 		free(tab[i++].copy);
// 	free(tab);
// 	return (0);
// }

// tab[0].size = ft_strlen(av[0]);
// *tab[0].size = ft_strlen(av[0]);
// tab[0]->size = ft_strlen(av[0]);
