/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwindey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:41:03 by gwindey           #+#    #+#             */
/*   Updated: 2026/03/02 10:41:05 by gwindey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	img_put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= img->w || y < 0 || y >= img->h)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	tex_get_pixel(t_img *tex, int x, int y)
{
	char	*src;

	src = tex->addr + (y * tex->line_len + x * (tex->bpp / 8));
	return (*(int *)src);
}

void	render_frame(t_game *g)
{
	render_ceiling_floor(g);
	render_walls(g);
	mlx_put_image_to_window(g->mlx, g->win, g->screen.img, 0, 0);
}
