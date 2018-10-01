/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:13:42 by aalokhin          #+#    #+#             */
/*   Updated: 2017/11/07 20:16:20 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static size_t			word_nb(char const *s, char c)
{
	size_t				count;

	count = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char				*ft_word(const char *s, char c)
{
	char				*word;
	int					i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (!(word = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char					**ft_strsplit(char const *str, char c)
{
	char				**ret;
	size_t				words;
	int					i;

	words = word_nb(str, c);
	i = 0;
	if (!(ret = (char**)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (*str)
	{
		while (*str && (*str == c))
			str++;
		if (*str && *str != c)
		{
			ret[i] = ft_word(str, c);
			i++;
			while (*str && *str != c)
				str++;
		}
	}
	ret[i] = NULL;
	return (ret);
}
