/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:03:29 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/16 16:21:20 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		while (*argv[argc - i])
		{
			write(1, argv[argc - i], 1);
			argv[argc - i]++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
