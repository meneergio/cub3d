/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:37:35 by dzotti            #+#    #+#             */
/*   Updated: 2025/04/29 14:10:03 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static int	word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**free_split(char **ptr, int word)
{
	int	i;

	i = 0;
	while (i < word)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

static char	**fill_split(const char *s, char c, char **ptr)
{
	int	i;
	int	word;
	int	len;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			len = word_len(&s[i], c);
			ptr[word] = ft_substr(s, i, len);
			if (!ptr[word])
				return (free_split(ptr, word));
			word++;
			i += len;
		}
		else
			i++;
	}
	ptr[word] = NULL;
	return (ptr);
}

char	**ft_split(const char *s, char c)
{
	char	**ptr;

	if (!s)
		return (NULL);
	ptr = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!ptr)
		return (NULL);
	return (fill_split(s, c, ptr));
}
