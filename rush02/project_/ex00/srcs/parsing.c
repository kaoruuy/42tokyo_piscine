/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 11:41:25 by tsadamor          #+#    #+#             */
/*   Updated: 2026/02/22 21:12:04 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*ft_strtrim_space(char *str)
{
	int	len;

	while (*str == ' ')
		str++;
	len = 0;
	while (str[len])
		len++;
	while (len >= 0 && str[len] == ' ')
	{
		str[len] = '\0';
		len--;
	}
	return (str);
}

int	count_entries(char *path)
{
	int		fd;
	int		count;
	int		has[2];
	char	c;
	int		status;

	count = 0;
	has[0] = 0;
	has[1] = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (read(fd, &c, 1) > 0)
	{
		status = is_valid_dict(has, c);
		if (status == -1)
		{
			close(fd);
			return (-1);
		}
		count = count + status;
	}
	if (has[0] && has[1])
		count++;
	return (close(fd), count);
}

int	set_entry(t_dict *entry, char *line)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	while (line[i] && line[i] != ':')
		i++;
	if (line[i] != ':')
		return (0);
	line[i] = '\0';
	start = 0;
	while (line[start] == ' ')
		start++;
	end = i - 1;
	while (end >= start && line[end] == ' ')
		end--;
	line[end + 1] = '\0';
	entry->key = ft_strdup(&line[start]);
	entry->value = ft_strdup(ft_strtrim_space(&line[i + 1]));
	return (1);
}

t_dict	*parse_dict(char *path)
{
	int		fd;
	int		size;
	int		i;
	t_dict	*tab;
	char	line[1024];

	size = count_entries(path);
	fd = open(path, O_RDONLY);
	if (size <= 0 || fd == -1)
		return (NULL);
	tab = malloc(sizeof(t_dict) * (size + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (get_next_line(fd, line) > 0 && i < size)
	{
		if (set_entry(&tab[i], line))
			i++;
	}
	tab[i].key = NULL;
	close(fd);
	return (tab);
}
