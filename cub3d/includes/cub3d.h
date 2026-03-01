/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 13:41:22 by dzotti            #+#    #+#             */
/*   Updated: 2026/02/27 13:41:22 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>

# include "libft.h"

# ifndef BUFSIZE
#  define BUFSIZE 1024
# endif

typedef struct s_map
{
	char	**grid;
	int		w;
	int		h;
}	t_map;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
	int	value;
}	t_rgb;

typedef struct s_player
{
	int		x;
	int		y;
	char	dir;
}	t_player;

typedef struct s_flood_ctx
{
	char	**grid;
	char	**visited;
	int		h;
	int		w;
}	t_flood_ctx;

typedef struct s_cfg
{
	char		*tex_path[4];
	t_rgb		floor;
	t_rgb		ceil;
	t_map		map;
	t_player	player;
}	t_cfg;

enum	e_tex
{
	TEX_NO = 0,
	TEX_SO = 1,
	TEX_WE = 2,
	TEX_EA = 3
};

enum	e_id
{
	ID_NONE = 0,
	ID_NO,
	ID_SO,
	ID_WE,
	ID_EA,
	ID_F,
	ID_C
};

void	cfg_init(t_cfg *cfg);
void	cfg_free(t_cfg *cfg);

int		error_msg(const char *msg);
int		error_sys(const char *where);

void	lines_free(char **lines);

char	*read_file_to_str(const char *path);
char	**split_lines(const char *s);

int		skip_spaces(const char *s, int i);
int		parse_id(const char *line);
int		is_map_line(const char *line);
int		find_map_start(char **lines);

int		parse_elements(t_cfg *cfg, char **lines, int map_start);
int		parse_tex_line(t_cfg *cfg, const char *line, int id);
int		parse_color_line(t_cfg *cfg, const char *line, int id);
int		validate_cfg_complete(t_cfg *cfg);

int		parse_map_grid(t_cfg *cfg, char **lines, int map_start);
int		pad_grid(char **grid, int h, int w);
int		parse_map_validate_player(t_cfg *cfg);
int		map_check_closed(t_cfg *cfg);

int		parse_cub(const char *path, t_cfg *cfg);

#endif
