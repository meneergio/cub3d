/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:56:49 by dzotti            #+#    #+#             */
/*   Updated: 2026/02/09 16:56:49 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_map_start(char **lines)
{
	int	i;
	int	k;
	int	id;

	if (!lines)
		return (-1);
	i = 0;
	while (lines[i])
	{
		k = skip_spaces(lines[i], 0);
		if (lines[i][k] == '\0')
			i++;
		else
		{
			id = parse_id(lines[i]);
			if (id != ID_NONE)
				i++;
			else if (is_map_line(lines[i]))
				return (i);
			else
				return (error_msg("unkown line before map"), -1);
		}
	}
	return (error_msg("no map found"), -1);
}
