/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:43:05 by bdudley           #+#    #+#             */
/*   Updated: 2018/11/07 22:42:36 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bsq.h"

int	ft_check_map(int fd, t_param **legend, int x, int y)
{
	int		ret;
	char	buf[BUF_SIZE];

	while ((ret = read(fd, buf, BUF_SIZE)) &&
			buf[0] != '\0' && y < (*legend)->y)
	{
		if (ret == -1)
			return (0);
		if (buf[0] == '\n')
			if (x == (*legend)->x)
			{
				x = 0;
				y++;
			}
			else
				return (0);
		else if (buf[0] == (*legend)->empty || buf[0] == (*legend)->obst)
			x++;
		else
			return (0);
	}
	if (y < (*legend)->y)
		return (0);
	return (1);
}
