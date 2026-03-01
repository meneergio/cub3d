/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 15:50:25 by dzotti            #+#    #+#             */
/*   Updated: 2026/02/05 15:50:25 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// eigen fout (bv map not closed)
int	error_msg(const char *msg)
{
	write(2, "Error\n", 6);
	if (msg != NULL)
	{
		while (*msg != '\0')
		{
			write(2, msg, 1);
			msg++;
		}
	}
	write(2, "\n", 1);
	return (1);
}

// systeemfout
int	error_sys(const char *where)
{
	write(2, "Error\n", 6);
	perror(where);
	return (1);
}
