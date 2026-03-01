/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:32:12 by dzotti            #+#    #+#             */
/*   Updated: 2026/02/10 13:32:12 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	id_to_tex_idx(int id)
{
	if (id == ID_NO)
		return (TEX_NO);
	if (id == ID_SO)
		return (TEX_SO);
	if (id == ID_WE)
		return (TEX_WE);
	if (id == ID_EA)
		return (TEX_EA);
	return (-1);
}

static char	*extract_tex_path(const char *line)
{
	int		i;
	char	*path;

	i = skip_spaces(line, 0);
	i += 2;
	i = skip_spaces(line, i);
	path = ft_strtrim(line + i, " \t");
	return (path);
}

int	parse_tex_line(t_cfg *cfg, const char *line, int id)
{
	int		tex_idx;
	char	*path;

	if (!cfg || !line)
		return (error_msg("parse_tex_line: null"), 1);
	tex_idx = id_to_tex_idx(id);
	if (tex_idx < 0)
		return (error_msg("parse_tex_line: bad id"), 1);
	if (cfg->tex_path[tex_idx] != NULL)
		return (error_msg("texture set twice"), 1);
	path = extract_tex_path(line);
	if (!path)
		return (error_msg("malloc fail"), 1);
	if (path[0] == '\0')
		return (free(path), error_msg("empty texture path"), 1);
	cfg->tex_path[tex_idx] = path;
	return (0);
}
