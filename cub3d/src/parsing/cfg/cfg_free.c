/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cfg_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 15:50:32 by dzotti            #+#    #+#             */
/*   Updated: 2026/02/05 15:50:32 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_grid(char **grid)
{
	int	i;

	if (!grid)
		return ;
	i = 0;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void	cfg_free(t_cfg *cfg)
{
	int	i;

	if (!cfg)
		return ;
	i = 0;
	while (i < 4)
	{
		free(cfg->tex_path[i]);
		cfg->tex_path[i] = NULL;
		i++;
	}
	free_grid(cfg->map.grid);
	cfg->map.grid = NULL;
}
