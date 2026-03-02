/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwindey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:40:48 by gwindey           #+#    #+#             */
/*   Updated: 2026/03/02 11:46:27 by gwindey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calc_col(t_col *col, t_ray *ray)
{
	col->line_h = (int)(WIN_H / ray->perp_wall_dist);
	col->draw_start = -col->line_h / 2 + WIN_H / 2;
	if (col->draw_start < 0)
		col->draw_start = 0;
	col->draw_end = col->line_h / 2 + WIN_H / 2;
	if (col->draw_end >= WIN_H)
		col->draw_end = WIN_H - 1;
}

static void	calc_tex_x(t_game *g, t_col *col, t_ray *ray)
{
	double	wall_x;
	int		tex_w;

	if (ray->side == 0)
		wall_x = g->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = g->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_w = g->tex[ray->tex_idx].w;
	col->tex_x = (int)(wall_x * (double)tex_w);
	if (ray->side == 0 && ray->ray_dir_x < 0)
		col->tex_x = tex_w - col->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y > 0)
		col->tex_x = tex_w - col->tex_x - 1;
}

static void	draw_tex_col(t_game *g, t_col *col, t_ray *ray, int x)
{
	int		y;
	int		tex_y;
	int		color;
	t_img	*tex;

	tex = &g->tex[ray->tex_idx];
	col->step = (double)tex->h / (double)col->line_h;
	col->tex_pos = (col->draw_start - WIN_H / 2 + col->line_h / 2) * col->step;
	y = col->draw_start;
	while (y <= col->draw_end)
	{
		tex_y = (int)col->tex_pos % tex->h;
		col->tex_pos += col->step;
		color = tex_get_pixel(tex, col->tex_x, tex_y);
		if (ray->side == 1)
			color = (color >> 1) & 0x7F7F7F;
		img_put_pixel(&g->screen, x, y, color);
		y++;
	}
}

void	draw_column(t_game *g, int x, t_ray *ray)
{
	t_col	col;

	calc_col(&col, ray);
	calc_tex_x(g, &col, ray);
	draw_tex_col(g, &col, ray, x);
}
