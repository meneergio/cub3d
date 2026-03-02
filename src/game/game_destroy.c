/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwindey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:38:01 by gwindey           #+#    #+#             */
/*   Updated: 2026/03/02 16:09:38 by gwindey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_destroy(t_game *g)
{
	int	i;

	if (!g)
		return ;
	if (g->mlx)
	{
		i = 0;
		while (i < 4)
		{
			if (g->tex[i].img)
				mlx_destroy_image(g->mlx, g->tex[i].img);
			i++;
		}
		if (g->screen.img)
			mlx_destroy_image(g->mlx, g->screen.img);
		if (g->win)
			mlx_destroy_window(g->mlx, g->win);
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
	cfg_free(g->cfg);
}
