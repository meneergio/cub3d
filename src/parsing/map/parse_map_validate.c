/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_validate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:00:20 by dzotti            #+#    #+#             */
/*   Updated: 2026/02/17 23:00:20 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_player(t_cfg *cfg, int x, int y, char dir)
{
	cfg->player.x = x;
	cfg->player.y = y;
	cfg->player.dir = dir;
}

static int	is_player_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

static int	is_allowed_map_char(char c)
{
	if (is_player_char(c) || c == '1' || c == '0' || c == ' ')
		return (1);
	return (0);
}

static int	handle_innerloop(t_cfg *cfg, int x, int y, int *player_count)
{
	char	c;

	c = cfg->map.grid[y][x];
	if (!is_allowed_map_char(c))
		return (error_msg("invalid map char"), 1);
	if (is_player_char(c))
	{
		(*player_count)++;
		if (*player_count > 1)
			return (error_msg("multiple players"), 1);
		set_player(cfg, x, y, c);
		cfg->map.grid[y][x] = '0';
	}
	return (0);
}

int	parse_map_validate_player(t_cfg *cfg)
{
	int		x;
	int		y;
	int		player_count;

	if (!cfg || !cfg->map.grid || cfg->map.h <= 0 || cfg->map.w <= 0)
		return (error_msg("validate map: bad args"), 1);
	y = 0;
	player_count = 0;
	while (y < cfg->map.h)
	{
		x = 0;
		while (x < cfg->map.w)
		{
			if (handle_innerloop(cfg, x, y, &player_count))
				return (1);
			x++;
		}
		y++;
	}
	if (player_count == 0)
		return (error_msg("missing player"), 1);
	return (0);
}
