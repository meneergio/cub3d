/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:18:30 by dzotti            #+#    #+#             */
/*   Updated: 2026/03/03 10:07:51 by gwindey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	fail_all(t_cfg *cfg, char *file, char **lines, char *msg)
{
	if (lines)
		lines_free(lines);
	if (file)
		free(file);
	if (cfg)
		cfg_free(cfg);
	if (msg)
		error_msg(msg);
	return (1);
}

static int	parse_cub_pipeline(t_cfg *cfg, char **lines, int map_start)
{
	if (parse_elements(cfg, lines, map_start))
		return (1);
	if (validate_cfg_complete(cfg))
		return (1);
	if (parse_map_grid(cfg, lines, map_start))
		return (1);
	if (parse_map_validate_player(cfg))
		return (1);
	if (map_check_closed(cfg))
		return (1);
	return (0);
}

int	parse_cub(const char *path, t_cfg *cfg)
{
	char	*file;
	char	**lines;
	int		map_start;

	if (!path || !cfg)
		return (error_msg("parse_cub: bad args"), 1);
	cfg_init(cfg);
	file = read_file_to_str(path);
	if (!file)
		return (fail_all(cfg, NULL, NULL, NULL));
	lines = split_lines(file);
	if (!lines)
		return (fail_all(cfg, file, NULL, "split_lines failed"));
	map_start = find_map_start(lines);
	if (map_start < 0)
		return (fail_all(cfg, file, lines, NULL));
	if (parse_cub_pipeline(cfg, lines, map_start))
		return (fail_all(cfg, file, lines, NULL));
	lines_free(lines);
	free(file);
	return (0);
}
