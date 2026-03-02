/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwindey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:39:16 by gwindey           #+#    #+#             */
/*   Updated: 2026/03/02 10:39:18 by gwindey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mlx_setup(t_game *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
		return (error_msg("mlx_init failed"), 1);
	g->win = mlx_new_window(g->mlx, WIN_W, WIN_H, "cub3D");
	if (!g->win)
		return (error_msg("mlx_new_window failed"), 1);
	g->screen.img = mlx_new_image(g->mlx, WIN_W, WIN_H);
	if (!g->screen.img)
		return (error_msg("mlx_new_image failed"), 1);
	g->screen.addr = mlx_get_data_addr(g->screen.img,
			&g->screen.bpp, &g->screen.line_len, &g->screen.endian);
	g->screen.w = WIN_W;
	g->screen.h = WIN_H;
	return (0);
}
