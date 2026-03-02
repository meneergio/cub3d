/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 13:42:48 by dzotti            #+#    #+#             */
/*   Updated: 2026/03/02 16:04:14 by gwindey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_extension(const char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 5)
		return (1);
	if (ft_strncmp(path + len - 4, ".cub", 4) != 0)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_cfg	cfg;

	if (ac != 2)
		return (error_msg("usage: ./cub3D map.cub"), 1);
	if (check_extension(av[1]))
		return (error_msg("invalid file extension"), 1);
	if (parse_cub(av[1], &cfg))
		return (1);
	return (game_start(&cfg));
}
