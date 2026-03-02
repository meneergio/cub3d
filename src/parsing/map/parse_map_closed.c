/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_closed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 21:46:57 by dzotti            #+#    #+#             */
/*   Updated: 2026/03/02 15:08:42 by gwindey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	visited_free(char **visited)
{
	int	y;

	if (!visited)
		return ;
	y = 0;
	while (visited[y])
		free(visited[y++]);
	free(visited);
}

static char	**visited_create(int h, int w)
{
	int		y;
	char	**vis;

	vis = malloc(sizeof(char *) * (h + 1));
	if (!vis)
		return (NULL);
	ft_bzero(vis, sizeof(char *) * (h + 1));
	y = 0;
	while (y < h)
	{
		vis[y] = malloc(sizeof(char) * w);
		if (!vis[y])
		{
			visited_free(vis);
			return (NULL);
		}
		ft_bzero(vis[y], w);
		y++;
	}
	return (vis);
}

static int	flood(t_flood_ctx *ctx, int x, int y)
{
	if (x < 0 || y < 0 || x >= ctx->w || y >= ctx->h)
		return (1);
	if (ctx->grid[y][x] == ' ')
		return (1);
	if (ctx->grid[y][x] == '1' || ctx->visited[y][x] == 1)
		return (0);
	ctx->visited[y][x] = 1;
	if (flood(ctx, x + 1, y) || flood(ctx, x - 1, y)
		|| flood(ctx, x, y + 1) || flood(ctx, x, y - 1))
		return (1);
	return (0);
}

int	map_check_closed(t_cfg *cfg)
{
	t_flood_ctx	f_ctx;
	int			res;

	f_ctx.h = cfg->map.h;
	f_ctx.w = cfg->map.w;
	f_ctx.grid = cfg->map.grid;
	f_ctx.visited = visited_create(f_ctx.h, f_ctx.w);
	if (!f_ctx.visited)
		return (error_msg("Malloc failed for visited grid"), 1);
	res = flood(&f_ctx, (int)cfg->player.x, (int)cfg->player.y);
	visited_free(f_ctx.visited);
	if (res)
		return (error_msg("Map is not closed"), 1);
	return (0);
}
