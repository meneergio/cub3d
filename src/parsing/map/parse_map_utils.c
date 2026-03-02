/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwindey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 13:46:28 by gwindey           #+#    #+#             */
/*   Updated: 2026/03/02 15:19:46 by gwindey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int is_line_empty(char *line)
{
    int i = 0;

    if (!line || line[0] == '\0')
        return (1);
    while (line[i])
    {
        if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n' &&
			line[i] != '\v' && line[i] != '\f' && line[i] != '\r')
            return (0);
        i++;
    }
    return (1);
}
