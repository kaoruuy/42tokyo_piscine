/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:42:09 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/19 20:10:07 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

char	*copy_word(char *str, char *charset)
{
	char	*word;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = 0;
	while (str[len] && !is_sep(str[len], charset))
	{
		if (!(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
			len++;
		i++;
	}
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && !is_sep(str[i], charset))
	{
		if (!(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		{
			word[j] = str[i];
			j++;
		}
		i++;
	}
	word[i] = '\0';
	return (word);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!is_sep(str[i], charset) && (i == 0 || is_sep(str[i - 1], charset)))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		words;
	int		len;
	char	**ans;

	words = count_words(str, charset);
	ans = malloc(sizeof(char *) * (words + 1));
	if (ans == NULL)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (!is_sep(*str, charset))
		{
			ans[i] = copy_word(str, charset);
			i++;
			while (*str && !is_sep(*str, charset))
				str++;
		}
		else
			str++;
	}
	ans[i] = NULL;
	return (ans);
}

#include <stdio.h>

int	main(void)
{
	char	*str;
	char	*charset;
	char	**ans;
	int		i;

	i = 0;
	str = "abc, def. ghe";
	charset = ",.";
	ans = ft_split(str, charset);
	while (ans[i])
	{
		printf("Word[%d]: %s\n", i, ans[i]);
		free(ans[i]);
		i++;
	}
	return (0);
}
