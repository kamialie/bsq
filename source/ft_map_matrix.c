/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:08:50 by rgyles            #+#    #+#             */
/*   Updated: 2018/11/07 17:22:15 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bsq.h"

char	*ft_write_line(char *line, char *buf)
{
	int i;

	i = 0;
	while (buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

void	ft_skip_first_line(int fd)
{
	char buf[1];

	while (buf[0] != '\n')
		read(fd, buf, 1);
}

char	**ft_create_map_matrix(int x, int y, int fd)
{
	int		line;
	int		ret;
	char	**map;
	char	buf[x + 2];

	line = 0;
	if (!(map = (char **)malloc(sizeof(*map) * (y + 1))))
		return (NULL);
	ft_skip_first_line(fd);
	while (line < y)
	{
		if (!(map[line] = (char *)malloc(sizeof(**map) * (x + 1))))
			return (NULL);
		if ((ret = read(fd, buf, x + 1)) == -1)
			return (NULL);
		buf[ret] = '\0';
		map[line] = ft_write_line(map[line], buf);
		line++;
	}
	if (close(fd) == -1)
		return (NULL);
	map[line] = 0;
	return (map);
}
