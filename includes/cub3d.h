/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 13:41:22 by dzotti            #+#    #+#             */
/*   Updated: 2026/03/02 15:48:48 by gwindey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <errno.h>
# include "mlx.h"
# include "libft.h"

# ifndef BUFSIZE
#  define BUFSIZE 1024
# endif

# define WIN_W       1280
# define WIN_H       720
# define MOVE_SPEED  0.05
# define ROT_SPEED   0.03
# define MARGIN      0.2

# define KC_ESC      65307
# define KC_W        119
# define KC_A        97
# define KC_S        115
# define KC_D        100
# define KC_LEFT     65361
# define KC_RIGHT    65363

# define KEY_W       0
# define KEY_A       1
# define KEY_S       2
# define KEY_D       3
# define KEY_LEFT    4
# define KEY_RIGHT   5

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

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		w;
	int		h;
}	t_img;

typedef struct s_ray
{
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		side;
	int		tex_idx;
}	t_ray;

typedef struct s_col
{
	int		line_h;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	double	tex_pos;
	double	step;
}	t_col;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	screen;
	t_img	tex[4];
	t_cfg	*cfg;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		keys[6];
}	t_game;

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

/* ---- parsing ---- */
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
int		check_all_zeros(t_cfg *cfg);
int		parse_cub(const char *path, t_cfg *cfg);
int		is_line_empty(char *line);

/* ---- game ---- */
int		game_start(t_cfg *cfg);
void	game_destroy(t_game *g);
void	game_init_player(t_game *g);

/* ---- mlx ---- */
int		mlx_setup(t_game *g);
int		key_press(int key, void *param);
int		key_release(int key, void *param);
int		handle_close(void *param);
int		game_loop(void *param);

/* ---- textures ---- */
int		tex_load_all(t_game *g);

/* ---- render ---- */
void	render_frame(t_game *g);
void	render_ceiling_floor(t_game *g);
void	render_walls(t_game *g);
void	draw_column(t_game *g, int x, t_ray *ray);
void	img_put_pixel(t_img *img, int x, int y, int color);
int		tex_get_pixel(t_img *tex, int x, int y);

/* ---- raycast ---- */
void	ray_init(t_game *g, int x, t_ray *ray);
void	dda_init(t_game *g, t_ray *ray);
void	dda_run(t_game *g, t_ray *ray);

/* ---- player ---- */
void	player_update(t_game *g);
void	player_move(t_game *g, double dx, double dy);
void	player_rotate(t_game *g, double angle);

#endif
