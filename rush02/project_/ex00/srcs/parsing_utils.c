/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:32:10 by tsadamor          #+#    #+#             */
/*   Updated: 2026/02/22 21:09:43 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_valid_dict(int *has, char c)
{
	if (c == '\n')
	{
		if (has[0] && has[1])
		{
			has[0] = 0;
			has[1] = 0;
			return (1);
		}
		if (!has[0] && !has[1])
			return (0);
		return (-1);
	}
	if (!has[1])
	{
		if (is_digit(c))
			has[0] = 1;
		else if (c == ':' && has[0])
			has[1] = 1;
		else if (c != ' ')
			return (-1);
	}
	else if (c == ':')
		return (-1);
	return (0);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dup;

	i = 0;
	while (src[i])
		i++;
	dup = (char *)malloc(sizeof(char) * (i + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	get_next_line(int fd, char *line)
{
	int	j;
	int	res;

	j = 0;
	res = 0;
	while (read(fd, &line[j], 1) > 0)
	{
		if (line[j] == '\n')
		{
			line[j] = '\0';
			return (1);
		}
		j++;
	}
	if (j > 0)
	{
		line[j] = '\0';
		return (1);
	}
	return (0);
}
