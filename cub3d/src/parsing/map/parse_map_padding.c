/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_padding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 21:47:04 by dzotti            #+#    #+#             */
/*   Updated: 2026/02/17 21:47:04 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*pad_dup(const char *s, int w)
{
	char	*out;
	int		i;
	int		len;

	if (!s || w <= 0)
		return (NULL);
	len = ft_strlen(s);
	out = (char *)malloc(sizeof(char) * (w + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (i < len)
	{
		out[i] = s[i];
		i++;
	}
	while (i < w)
	{
		out[i] = ' ';
		i++;
	}
	out[w] = '\0';
	return (out);
}

int	pad_grid(char **grid, int h, int w)
{
	int		i;
	int		len;
	char	*new;

	if (!grid || h <= 0 || w <= 0)
		return (1);
	i = 0;
	while (i < h)
	{
		if (!grid[i])
			return (1);
		len = ft_strlen(grid[i]);
		if (len < w)
		{
			new = pad_dup(grid[i], w);
			if (!new)
				return (1);
			free(grid[i]);
			grid[i] = new;
		}
		i++;
	}
	return (0);
}
