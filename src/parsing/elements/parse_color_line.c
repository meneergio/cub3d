/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:17:07 by dzotti            #+#    #+#             */
/*   Updated: 2026/02/11 12:17:07 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	parse_number_255(const char *s, int *i, int *out)
{
	int	n;

	if (!s || !i || !out)
		return (1);
	if (!is_digit(s[*i]))
		return (1);
	n = 0;
	while (is_digit(s[*i]))
	{
		n = n * 10 + (s[*i] - '0');
		if (n > 255)
			return (1);
		(*i)++;
	}
	*out = n;
	return (0);
}

static int	expect_char(const char *s, int *i, char c)
{
	if (!s || !i)
		return (1);
	if (s[*i] != c)
		return (1);
	(*i)++;
	return (0);
}

static int	parse_rgb_tail(const char *line, int start, t_rgb *dst)
{
	int	i;

	if (!line || !dst)
		return (1);
	i = start;
	if (parse_number_255(line, &i, &dst->r))
		return (1);
	if (expect_char(line, &i, ','))
		return (1);
	if (parse_number_255(line, &i, &dst->g))
		return (1);
	if (expect_char(line, &i, ','))
		return (1);
	if (parse_number_255(line, &i, &dst->b))
		return (1);
	i = skip_spaces(line, i);
	if (line[i] != '\0')
		return (1);
	dst->value = (dst->r << 16) | (dst->g << 8) | dst->b;
	return (0);
}

int	parse_color_line(t_cfg *cfg, const char *line, int id)
{
	int		i;
	t_rgb	tmp;

	if (!cfg || !line)
		return (error_msg("parse_color_line: null"), 1);
	if (id != ID_F && id != ID_C)
		return (error_msg("parse_color_line: bad id"), 1);
	if (id == ID_F && cfg->floor.value != -1)
		return (error_msg("floor color set twice"), 1);
	if (id == ID_C && cfg->ceil.value != -1)
		return (error_msg("ceiling color set twice"), 1);
	i = skip_spaces(line, 0);
	i += 1;
	i = skip_spaces(line, i);
	if (line[i] == '\0')
		return (error_msg("empty rgb"), 1);
	if (parse_rgb_tail(line, i, &tmp))
		return (error_msg("invalid rgb format"), 1);
	if (id == ID_F)
		cfg->floor = tmp;
	else
		cfg->ceil = tmp;
	return (0);
}
