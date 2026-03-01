/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_map_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:56:30 by dzotti            #+#    #+#             */
/*   Updated: 2026/02/12 13:56:30 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_map_lines(char **lines, int map_start)
{
	int	i;

	if (!lines || map_start < 0)
		return (0);
	i = map_start;
	while (lines[i])
		i++;
	while (i > map_start && lines[i - 1][0] == '\0')
		i--;
	return (i - map_start);
}

static int	fill_grid(char **grid, char **lines, int map_start, int h)
{
	int	i;

	i = 0;
	while (i < h)
	{
		grid[i] = ft_strdup(lines[map_start + i]);
		if (!grid[i])
		{
			grid[i] = NULL;
			lines_free(grid);
			error_msg("ft_strdup failed");
			return (1);
		}
		i++;
	}
	grid[h] = NULL;
	return (0);
}

static int	map_width(char **grid)
{
	int	max;
	int	len;
	int	i;

	if (!grid)
		return (0);
	max = 0;
	i = 0;
	while (grid[i])
	{
		len = ft_strlen(grid[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

static int	finalize_grid(t_cfg *cfg, char **grid, int h)
{
	int	w;

	w = map_width(grid);
	if (w <= 0)
	{
		lines_free(grid);
		return (error_msg("map width invalid"), 1);
	}
	if (pad_grid(grid, h, w) != 0)
	{
		lines_free(grid);
		return (error_msg("padding invalid"), 1);
	}
	cfg->map.grid = grid;
	cfg->map.h = h;
	cfg->map.w = w;
	return (0);
}

int	parse_map_grid(t_cfg *cfg, char **lines, int map_start)
{
	int		h;
	char	**grid;

	if (!cfg || !lines || map_start < 0)
		return (error_msg("parse_map_grid: bad args"), 1);
	h = count_map_lines(lines, map_start);
	if (h <= 0)
		return (error_msg("map height invalid"), 1);
	grid = malloc(sizeof(char *) * (h + 1));
	if (!grid)
		return (error_msg("fail malloc grid"), 1);
	if (fill_grid(grid, lines, map_start, h) != 0)
		return (1);
	return (finalize_grid(cfg, grid, h));
}
