/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 13:42:48 by dzotti            #+#    #+#             */
/*   Updated: 2026/02/27 13:42:48 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_map(t_cfg *cfg)
{
	int	i;

	printf("map.h=%d map.w=%d\n", cfg->map.h, cfg->map.w);
	printf("player: x=%d y=%d dir=%c\n",
		cfg->player.x, cfg->player.y, cfg->player.dir);
	i = 0;
	while (cfg->map.grid && cfg->map.grid[i])
	{
		printf("map[%d]=|%s|\n", i, cfg->map.grid[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_cfg	cfg;

	if (ac != 2)
		return (error_msg("usage: ./cub3D map.cub"), 1);
	if (parse_cub(av[1], &cfg))
		return (1);
	print_map(&cfg);
	cfg_free(&cfg);
	return (0);
}
