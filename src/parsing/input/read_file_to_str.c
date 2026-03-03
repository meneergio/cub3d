/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:43:07 by dzotti            #+#    #+#             */
/*   Updated: 2026/03/03 09:57:55 by gwindey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_copy_n(char *dst, const char *src, int n)
{
	int	i;

	if (!dst || !src)
		return ;
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}

static char	*append_chunk(char *all, char *buf, int n)
{
	int		old_len;
	char	*new;

	old_len = ft_strlen(all);
	new = (char *)malloc(old_len + n + 1);
	if (!new)
		return (NULL);
	if (all)
		ft_copy_n(new, all, old_len);
	ft_copy_n(new + old_len, buf, n);
	new[old_len + n] = '\0';
	free(all);
	return (new);
}

static char	*read_fd_to_str(int fd)
{
	int		n;
	char	*tmp;
	char	*all;
	char	buf[BUFSIZE];

	all = (char *)malloc(1);
	if (!all)
		return (NULL);
	all[0] = '\0';
	n = read(fd, buf, BUFSIZE);
	while (n > 0)
	{
		tmp = append_chunk(all, buf, n);
		if (!tmp)
			return (free(all), NULL);
		all = tmp;
		n = read(fd, buf, BUFSIZE);
	}
	if (n < 0)
		return (error_sys("read"), free(all), NULL);
	return (all);
}

char	*read_file_to_str(const char *path)
{
	int		fd;
	char	*all;

	if (!path)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (error_sys(path), NULL);
	all = read_fd_to_str(fd);
	close(fd);
	return (all);
}
