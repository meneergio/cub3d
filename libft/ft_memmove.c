/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:59:29 by dzotti            #+#    #+#             */
/*   Updated: 2025/04/16 11:59:29 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*p;
	const unsigned char	*s;

	p = (unsigned char *) dst;
	s = (const unsigned char *) src;
	if (p == s || n == 0)
		return (dst);
	if (p < s)
	{
		while (n--)
			*p++ = *s++;
	}
	else
	{
		p += n;
		s += n;
		while (n--)
			*(--p) = *(--s);
	}
	return (dst);
}
