/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cfg_complete.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 20:19:53 by dzotti            #+#    #+#             */
/*   Updated: 2026/02/11 20:19:53 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_cfg_complete(t_cfg *cfg)
{
	if (!cfg)
		return (error_msg("validate_cfg_complete: null"), 1);
	if (!cfg->tex_path[TEX_NO])
		return (error_msg("missing NO texture"), 1);
	if (!cfg->tex_path[TEX_SO])
		return (error_msg("missing SO texture"), 1);
	if (!cfg->tex_path[TEX_WE])
		return (error_msg("missing WE texture"), 1);
	if (!cfg->tex_path[TEX_EA])
		return (error_msg("missing EA texture"), 1);
	if (cfg->floor.value == -1)
		return (error_msg("missing floor color"), 1);
	if (cfg->ceil.value == -1)
		return (error_msg("missing ceiling color"), 1);
	return (0);
}
