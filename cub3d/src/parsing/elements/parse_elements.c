/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:10:48 by dzotti            #+#    #+#             */
/*   Updated: 2026/02/09 21:10:48 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_empty_line(const char *line)
{
	int	i;

	if (!line)
		return (1);
	i = skip_spaces(line, 0);
	return (line[i] == '\0');
}

static int	handle_element_line(t_cfg *cfg, char *line)
{
	int	id;

	id = parse_id(line);
	if (id == ID_NONE)
		return (error_msg("invalid line in elements"), 1);
	if (id == ID_NO || id == ID_SO || id == ID_WE || id == ID_EA)
		return (parse_tex_line(cfg, line, id));
	if (id == ID_F || id == ID_C)
		return (parse_color_line(cfg, line, id));
	return (0);
}

int	parse_elements(t_cfg *cfg, char **lines, int map_start)
{
	int	i;

	if (!cfg || !lines)
		return (error_msg("parse_elements: null"), 1);
	i = 0;
	while (i < map_start && lines[i])
	{
		if (!is_empty_line(lines[i]) && handle_element_line(cfg, lines[i]))
			return (1);
		i++;
	}
	return (0);
}
