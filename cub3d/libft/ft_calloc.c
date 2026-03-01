/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:11:21 by dzotti            #+#    #+#             */
/*   Updated: 2025/04/29 14:20:37 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	void	*copy;

	if (count != 0 && (count * size) / count != size)
		return (NULL);
	total = count * size;
	copy = malloc(total);
	if (!copy)
		return (NULL);
	ft_bzero(copy, total);
	return (copy);
}
