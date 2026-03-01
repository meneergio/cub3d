/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_closed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 21:46:57 by dzotti            #+#    #+#             */
/*   Updated: 2026/02/18 21:46:57 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	visited_free(char **visited)
{
	int	y;

	if (!visited)
		return ;
	y = 0;
	while (visited[y] != NULL)
	{
		free(visited[y]);
		y++;
	}
	free(visited);
}

static char	**visited_create(int h, int w)
{
	int		y;
	char	**visited;

	if (h <= 0 || w <= 0)
		return (NULL);
	visited = (char **)malloc(sizeof(char *) * (h + 1));
	if (!visited)
		return (NULL);
	ft_bzero(visited, sizeof(char *) * (h + 1));
	y = 0;
	while (y < h)
	{
		visited[y] = (char *)malloc(sizeof(char) * w);
		if (!visited[y])
			return (visited_free(visited), NULL);
		ft_bzero(visited[y], w);
		y++;
	}
	return (visited);
}

static int	flood(t_flood_ctx *ctx, int x, int y)
{
	if (x < 0 || y < 0 || x >= ctx->w || y >= ctx->h)
		return (1);
	if (ctx->grid[y][x] == ' ')
		return (1);
	if (ctx->grid[y][x] == '1')
		return (0);
	if (ctx->visited[y][x] == 1)
		return (0);
	ctx->visited[y][x] = 1;
	if (flood(ctx, x + 1, y))
		return (1);
	if (flood(ctx, x - 1, y))
		return (1);
	if (flood(ctx, x, y + 1))
		return (1);
	if (flood(ctx, x, y - 1))
		return (1);
	return (0);
}

int	map_check_closed(t_cfg *cfg)
{
	t_flood_ctx	ctx;
	char		**visited;

	if (!cfg || !cfg->map.grid || cfg->map.h <= 0 || cfg->map.w <= 0)
		return (error_msg("map_check_closed: bad args"), 1);
	if (cfg->player.x < 0 || cfg->player.y < 0
		|| cfg->player.x >= cfg->map.w || cfg->player.y >= cfg->map.h)
		return (error_msg("map_check_closed: player out of bounds"), 1);
	visited = visited_create(cfg->map.h, cfg->map.w);
	if (!visited)
		return (error_msg("visited_create failed"), 1);
	ctx.grid = cfg->map.grid;
	ctx.visited = visited;
	ctx.h = cfg->map.h;
	ctx.w = cfg->map.w;
	if (flood(&ctx, cfg->player.x, cfg->player.y))
		return (visited_free(visited), error_msg("map not closed"), 1);
	visited_free(visited);
	return (0);
}
