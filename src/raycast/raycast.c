/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwindey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:40:23 by gwindey           #+#    #+#             */
/*   Updated: 2026/03/02 10:40:25 by gwindey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_init(t_game *g, int x, t_ray *ray)
{
	double	cam_x;

	cam_x = 2.0 * x / (double)WIN_W - 1.0;
	ray->ray_dir_x = g->dir_x + g->plane_x * cam_x;
	ray->ray_dir_y = g->dir_y + g->plane_y * cam_x;
	ray->map_x = (int)g->pos_x;
	ray->map_y = (int)g->pos_y;
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1.0 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1.0 / ray->ray_dir_y);
}

static void	set_tex_idx(t_ray *ray)
{
	if (ray->side == 1 && ray->step_y < 0)
		ray->tex_idx = TEX_NO;
	else if (ray->side == 1 && ray->step_y > 0)
		ray->tex_idx = TEX_SO;
	else if (ray->side == 0 && ray->step_x > 0)
		ray->tex_idx = TEX_EA;
	else
		ray->tex_idx = TEX_WE;
}

void	render_walls(t_game *g)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < WIN_W)
	{
		ray_init(g, x, &ray);
		dda_init(g, &ray);
		dda_run(g, &ray);
		set_tex_idx(&ray);
		draw_column(g, x, &ray);
		x++;
	}
}
