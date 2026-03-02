/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:56:30 by dzotti            #+#    #+#             */
/*   Updated: 2026/03/02 15:18:56 by gwindey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_map_lines(char **lines, int map_start)
{
	int	i;
	int	count;

	if (!lines || map_start < 0)
		return (0);
	i = map_start;
	count = 0;
	while (lines[i] && !is_line_empty(lines[i]))
	{
		count++;
		i++;
	}
	while (lines[i] && is_line_empty(lines[i]))
    	i++;
	if (lines[i] != NULL && !is_line_empty(lines[i]))
    	return (error_msg("Map is separated by empty lines"), -1);
	return (count);
}

static int	fill_grid(t_cfg *cfg, char **lines, int map_start)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (i < cfg->map.h)
	{
		cfg->map.grid[i] = malloc(sizeof(char) * (cfg->map.w + 1));
		if (!cfg->map.grid[i])
		{
			while (--i >= 0)
				free(cfg->map.grid[i]);
			return (error_msg("Malloc failed in fill_grid"), 1);
		}
		len = ft_strlen(lines[map_start + i]);
		ft_memcpy(cfg->map.grid[i], lines[map_start + i], len);
		j = len;
		while (j < cfg->map.w)
			cfg->map.grid[i][j++] = ' ';
		cfg->map.grid[i][cfg->map.w] = '\0';
		i++;
	}
	cfg->map.grid[cfg->map.h] = NULL;
	return (0);
}

int	parse_map_grid(t_cfg *cfg, char **lines, int map_start)
{
	int	i;
	int	len;

	cfg->map.h = count_map_lines(lines, map_start);
	if (cfg->map.h <= 0)
		return (1);
	cfg->map.w = 0;
	i = 0;
	while (i < cfg->map.h)
	{
		len = ft_strlen(lines[map_start + i]);
		if (len > cfg->map.w)
			cfg->map.w = len;
		i++;
	}
	cfg->map.grid = malloc(sizeof(char *) * (cfg->map.h + 1));
	if (!cfg->map.grid)
		return (error_msg("Malloc failed for map grid"), 1);
	if (fill_grid(cfg, lines, map_start))
	{
		free(cfg->map.grid);
		cfg->map.grid = NULL;
		return (1);
	}
	return (0);
}
