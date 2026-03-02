/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwindey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 13:46:28 by gwindey           #+#    #+#             */
/*   Updated: 2026/03/02 16:29:17 by gwindey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_line_empty(char *line)
{
	int	i;

	i = 0;
	if (!line || line[0] == '\0')
		return (1);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n'
			&& line[i] != '\v' && line[i] != '\f' && line[i] != '\r')
			return (0);
		i++;
	}
	return (1);
}

static int	is_open_neighbor(t_cfg *cfg, int nx, int ny)
{
	if (nx < 0 || ny < 0 || nx >= cfg->map.w || ny >= cfg->map.h)
		return (1);
	if (cfg->map.grid[ny][nx] == ' ')
		return (1);
	return (0);
}

static int	check_zero_cell(t_cfg *cfg, int x, int y)
{
	if (cfg->map.grid[y][x] != '0')
		return (0);
	if (is_open_neighbor(cfg, x + 1, y))
		return (1);
	if (is_open_neighbor(cfg, x - 1, y))
		return (1);
	if (is_open_neighbor(cfg, x, y + 1))
		return (1);
	if (is_open_neighbor(cfg, x, y - 1))
		return (1);
	return (0);
}

int	check_all_zeros(t_cfg *cfg)
{
	int	x;
	int	y;

	y = 0;
	while (y < cfg->map.h)
	{
		x = 0;
		while (x < cfg->map.w)
		{
			if (check_zero_cell(cfg, x, y))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
