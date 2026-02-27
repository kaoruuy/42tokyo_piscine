/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:31:25 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/25 10:31:26 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

static char	*append_chunk(char *buf, int total, char *chunk, int bytes)
{
	char	*tmp;
	int		i;

	tmp = malloc(total + bytes + 1);
	if (!tmp)
	{
		free(buf);
		return (NULL);
	}
	i = 0;
	while (i < total)
	{
		tmp[i] = buf[i];
		i++;
	}
	i = 0;
	while (i < bytes)
	{
		tmp[total + i] = chunk[i];
		i++;
	}
	tmp[total + bytes] = '\0';
	free(buf);
	return (tmp);
}

static char	*read_loop(int fd, char *buf, int total)
{
	char	chunk[4096];
	int		bytes;

	bytes = read(fd, chunk, 4095);
	while (bytes > 0)
	{
		chunk[bytes] = '\0';
		buf = append_chunk(buf, total, chunk, bytes);
		if (!buf)
			return (NULL);
		total += bytes;
		bytes = read(fd, chunk, 4095);
	}
	if (bytes < 0)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}

char	*read_file(int fd)
{
	char	*buf;

	buf = malloc(1);
	if (!buf)
		return (NULL);
	buf[0] = '\0';
	return (read_loop(fd, buf, 0));
}
