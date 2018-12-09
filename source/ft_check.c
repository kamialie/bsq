/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:41:45 by bdudley           #+#    #+#             */
/*   Updated: 2018/11/07 19:19:13 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bsq.h"

int	ft_check(char *file_name, t_param *legend)
{
	int		fd;
	int		ret;
	int		count;
	char	buf[BUF_SIZE];

	count = 0;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (0);
	if (!(ft_valid_legend(ft_legend(fd), &legend)))
		return (0);
	while ((ret = read(fd, buf, BUF_SIZE)) && buf[0] != '\n')
	{
		if (ret == -1)
			return (0);
		if (buf[0] == legend->empty || buf[0] == legend->obst)
			count++;
		else
			return (0);
	}
	legend->x = count;
	if (!(ft_check_map(fd, &legend, 0, 1)) || close(fd) == -1)
		return (0);
	return (1);
}
