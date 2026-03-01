/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cfg_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 15:50:38 by dzotti            #+#    #+#             */
/*   Updated: 2026/02/05 15:50:38 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cfg_init(t_cfg *cfg)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		cfg->tex_path[i] = NULL;
		i++;
	}
	cfg->floor.r = -1;
	cfg->floor.g = -1;
	cfg->floor.b = -1;
	cfg->floor.value = -1;
	cfg->ceil.r = -1;
	cfg->ceil.g = -1;
	cfg->ceil.b = -1;
	cfg->ceil.value = -1;
	cfg->map.grid = NULL;
	cfg->map.w = 0;
	cfg->map.h = 0;
	cfg->player.x = -1;
	cfg->player.y = -1;
	cfg->player.dir = 0;
}
