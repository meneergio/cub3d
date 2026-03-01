/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:38:12 by dzotti            #+#    #+#             */
/*   Updated: 2026/02/07 17:38:12 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	parse_id(const char *line)
{
	int	i;

	if (!line)
		return (ID_NONE);
	i = skip_spaces(line, 0);
	if (line[i] == 'N' && line[i + 1] == 'O' && is_space(line[i + 2]))
		return (ID_NO);
	if (line[i] == 'S' && line[i + 1] == 'O' && is_space(line[i + 2]))
		return (ID_SO);
	if (line[i] == 'W' && line[i + 1] == 'E' && is_space(line[i + 2]))
		return (ID_WE);
	if (line[i] == 'E' && line[i + 1] == 'A' && is_space(line[i + 2]))
		return (ID_EA);
	if (line[i] == 'F' && is_space(line[i + 1]))
		return (ID_F);
	if (line[i] == 'C' && is_space(line[i + 1]))
		return (ID_C);
	return (ID_NONE);
}
