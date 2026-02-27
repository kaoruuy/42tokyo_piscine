/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:42:25 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/22 15:57:53 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	count_total_len(int size, char *strs[], char *sep)
{
	int	i;
	int	j;
	int	len;
	int	sep_len;

	i = 0;
	len = 0;
	sep_len = 0;
	while (sep[sep_len])
		sep_len++;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			j++;
			len++;
		}
		if (i < size - 1)
			len += sep_len;
		i++;
	}
	return (len);
}

void	copy(int size, char *strs[], char *sep, char *ans)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			ans[k++] = strs[i][j++];
		if (i < size - 1)
		{
			j = 0;
			while (sep[j])
				ans[k++] = sep[j++];
		}
		i++;
	}
	ans[k] = '\0';
}

char	*ft_strjoin(int size, char *strs[], char *sep)
{
	int		total_len;
	char	*ans;

	if (size <= 0)
	{
		ans = malloc(1);
		if (ans)
			ans[0] = '\0';
		return ((char *)malloc(1));
	}
	total_len = count_total_len(size, strs, sep);
	ans = (char *)malloc(sizeof(char) * (total_len + 1));
	if (ans == NULL)
		return (0);
	copy(size, strs, sep, ans);
	return (ans);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*strs[] = {"abc", "def", "ghi"};
// 	char	*result;

// 	result = ft_strjoin(3, strs, ", ");
// 	if (result)
// 	{
// 		printf("%s\n", result);
// 		free(result);
// 	}
// 	return (0);
// }
