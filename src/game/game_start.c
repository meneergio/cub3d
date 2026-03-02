/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwindey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:38:19 by gwindey           #+#    #+#             */
/*   Updated: 2026/03/02 10:38:22 by gwindey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_dir_ns(t_game *g, char dir)
{
	if (dir == 'N')
	{
		g->dir_x = 0;
		g->dir_y = -1;
		g->plane_x = 0.66;
		g->plane_y = 0;
	}
	else
	{
		g->dir_x = 0;
		g->dir_y = 1;
		g->plane_x = -0.66;
		g->plane_y = 0;
	}
}

static void	set_dir_ew(t_game *g, char dir)
{
	if (dir == 'E')
	{
		g->dir_x = 1;
		g->dir_y = 0;
		g->plane_x = 0;
		g->plane_y = 0.66;
	}
	else
	{
		g->dir_x = -1;
		g->dir_y = 0;
		g->plane_x = 0;
		g->plane_y = -0.66;
	}
}

void	game_init_player(t_game *g)
{
	char	dir;

	g->pos_x = (double)g->cfg->player.x + 0.5;
	g->pos_y = (double)g->cfg->player.y + 0.5;
	dir = g->cfg->player.dir;
	if (dir == 'N' || dir == 'S')
		set_dir_ns(g, dir);
	else
		set_dir_ew(g, dir);
	ft_bzero(g->keys, sizeof(int) * 6);
}

int	game_start(t_cfg *cfg)
{
	t_game	g;

	ft_bzero(&g, sizeof(t_game));
	g.cfg = cfg;
	if (mlx_setup(&g))
		return (game_destroy(&g), 1);
	if (tex_load_all(&g))
		return (game_destroy(&g), 1);
	game_init_player(&g);
	mlx_loop_hook(g.mlx, game_loop, &g);
	mlx_hook(g.win, 17, 0, handle_close, &g);
	mlx_hook(g.win, 2, 1L << 0, key_press, &g);
	mlx_hook(g.win, 3, 1L << 1, key_release, &g);
	mlx_loop(g.mlx);
	game_destroy(&g);
	return (0);
}
