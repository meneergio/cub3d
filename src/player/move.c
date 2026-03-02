/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwindey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:39:46 by gwindey           #+#    #+#             */
/*   Updated: 2026/03/02 10:39:48 by gwindey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	can_move(t_game *g, double x, double y)
{
	char	c;

	if (y < 0 || y >= g->cfg->map.h || x < 0 || x >= g->cfg->map.w)
		return (0);
	c = g->cfg->map.grid[(int)y][(int)x];
	return (c != '1' && c != ' ');
}

void	player_move(t_game *g, double dx, double dy)
{
	double	mx;
	double	my;

	mx = (dx > 0) ? MARGIN : -MARGIN;
	my = (dy > 0) ? MARGIN : -MARGIN;
	if (dx != 0 && can_move(g, g->pos_x + dx + mx, g->pos_y))
		g->pos_x += dx;
	if (dy != 0 && can_move(g, g->pos_x, g->pos_y + dy + my))
		g->pos_y += dy;
}

static void	move_accumulate(t_game *g, double *dx, double *dy)
{
	if (g->keys[KEY_W])
	{
		*dx += g->dir_x * MOVE_SPEED;
		*dy += g->dir_y * MOVE_SPEED;
	}
	if (g->keys[KEY_S])
	{
		*dx -= g->dir_x * MOVE_SPEED;
		*dy -= g->dir_y * MOVE_SPEED;
	}
	if (g->keys[KEY_A])
	{
		*dx += g->dir_y * MOVE_SPEED;
		*dy -= g->dir_x * MOVE_SPEED;
	}
	if (g->keys[KEY_D])
	{
		*dx -= g->dir_y * MOVE_SPEED;
		*dy += g->dir_x * MOVE_SPEED;
	}
}

void	player_update(t_game *g)
{
	double	dx;
	double	dy;

	dx = 0;
	dy = 0;
	move_accumulate(g, &dx, &dy);
	if (dx != 0 || dy != 0)
		player_move(g, dx, dy);
	if (g->keys[KEY_LEFT])
		player_rotate(g, -ROT_SPEED);
	if (g->keys[KEY_RIGHT])
		player_rotate(g, ROT_SPEED);
}
