/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwindey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:40:35 by gwindey           #+#    #+#             */
/*   Updated: 2026/03/02 10:40:37 by gwindey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fill_row(t_img *img, int y, int color, int w)
{
	int	x;

	x = 0;
	while (x < w)
	{
		img_put_pixel(img, x, y, color);
		x++;
	}
}

void	render_ceiling_floor(t_game *g)
{
	int	y;

	y = 0;
	while (y < WIN_H / 2)
	{
		fill_row(&g->screen, y, g->cfg->ceil.value, WIN_W);
		y++;
	}
	while (y < WIN_H)
	{
		fill_row(&g->screen, y, g->cfg->floor.value, WIN_W);
		y++;
	}
}
