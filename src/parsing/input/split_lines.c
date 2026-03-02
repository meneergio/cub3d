/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 21:09:27 by dzotti            #+#    #+#             */
/*   Updated: 2026/02/06 21:09:27 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_lines(const char *s)
{
	int	i;
	int	count;

	if (!s)
		return (0);
	i = 0;
	count = 1;
	while (s[i])
	{
		if (s[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

static char	*dup_range(const char *s, int start, int end)
{
	char	*new;
	int		n;
	int		i;

	n = end - start;
	new = (char *)malloc(sizeof(char) * (n + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < n)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static char	**free_lines_null(char **lines)
{
	lines_free(lines);
	return (NULL);
}

static char	**fill_lines(const char *s, char **lines)
{
	int		i;
	int		start;
	int		j;

	i = 0;
	start = 0;
	j = 0;
	while (1)
	{
		if (s[i] == '\n' || s[i] == '\0')
		{
			lines[j] = dup_range(s, start, i);
			if (!lines[j])
				return (free_lines_null(lines));
			j++;
			if (s[i] == '\0')
				break ;
			start = i + 1;
		}
		i++;
	}
	lines[j] = NULL;
	return (lines);
}

char	**split_lines(const char *s)
{
	char	**lines;

	if (!s)
		return (NULL);
	lines = (char **)malloc(sizeof(char *) * (count_lines(s) + 1));
	if (!lines)
		return (NULL);
	return (fill_lines(s, lines));
}
