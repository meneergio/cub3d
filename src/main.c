/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 13:42:48 by dzotti            #+#    #+#             */
/*   Updated: 2026/03/02 10:25:33 by gwindey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cfg	cfg;

	if (ac != 2)
		return (error_msg("usage: ./cub3D map.cub"), 1);
	if (parse_cub(av[1], &cfg))
		return (1);
	return (game_start(&cfg));
}
