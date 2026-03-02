/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwindey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:41:16 by gwindey           #+#    #+#             */
/*   Updated: 2026/03/02 10:41:17 by gwindey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	load_one(t_game *g, int i)
{
	g->tex[i].img = mlx_xpm_file_to_image(g->mlx,
			g->cfg->tex_path[i], &g->tex[i].w, &g->tex[i].h);
	if (!g->tex[i].img)
		return (error_msg("texture load failed"), 1);
	g->tex[i].addr = mlx_get_data_addr(g->tex[i].img,
			&g->tex[i].bpp, &g->tex[i].line_len, &g->tex[i].endian);
	return (0);
}

int	tex_load_all(t_game *g)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (load_one(g, i))
			return (1);
		i++;
	}
	return (0);
}
