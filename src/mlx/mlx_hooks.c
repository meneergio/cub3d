/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwindey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:39:05 by gwindey           #+#    #+#             */
/*   Updated: 2026/03/02 10:39:07 by gwindey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_key_state(t_game *g, int key, int state)
{
	if (key == KC_W)
		g->keys[KEY_W] = state;
	else if (key == KC_A)
		g->keys[KEY_A] = state;
	else if (key == KC_S)
		g->keys[KEY_S] = state;
	else if (key == KC_D)
		g->keys[KEY_D] = state;
	else if (key == KC_LEFT)
		g->keys[KEY_LEFT] = state;
	else if (key == KC_RIGHT)
		g->keys[KEY_RIGHT] = state;
}

int	key_press(int key, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (key == KC_ESC)
		handle_close(g);
	set_key_state(g, key, 1);
	return (0);
}

int	key_release(int key, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	set_key_state(g, key, 0);
	return (0);
}

int	handle_close(void *param)
{
	t_game	*g;

	g = (t_game *)param;
	game_destroy(g);
	exit(0);
}
