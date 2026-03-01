/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 18:18:27 by dzotti            #+#    #+#             */
/*   Updated: 2026/02/07 18:18:27 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map_line(const char *line)
{
	int	i;
	int	tile;

	if (!line)
		return (0);
	i = 0;
	tile = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			i++;
		else if (line[i] == '0' || line[i] == '1'
			|| line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W')
		{
			tile = 1;
			i++;
		}
		else
			return (0);
	}
	return (tile);
}
