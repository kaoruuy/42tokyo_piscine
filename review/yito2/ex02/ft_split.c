/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:53:56 by kayoshid          #+#    #+#             */
/*   Updated: 2026/02/27 09:12:34 by kayoshid         ###   ########.fr       */
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

int	count_word_len(char *str, char *charset)
{
	int	len;

	len = 0;
	while (str[len] && !is_sep(str[len], charset))
	{
		len++;
	}
	return (len);
}

char	*copy_word(char *str, char *charset)
{
	char	*word;
	int		i;
	int		j;
	int		len;

	len = count_word_len(str, charset);
	word = (char *)malloc(sizeof(word) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && !is_sep(str[i], charset))
		word[j++] = str[i++];
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

// #include <stdio.h>

// int	main(void)
// {
// 	char	*str;
// 	char	*charset;
// 	char	**ans;
// 	int		i;

// 	i = 0;
// 	str = "abc, def. ghe";
// 	charset = ",.";
// 	ans = ft_split(str, charset);
// 	while (ans[i])
// 	{
// 		printf("Word[%d]: %s\n", i, ans[i]);
// 		free(ans[i]);
// 		i++;
// 	}
// 	return (0);
// }
