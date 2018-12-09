/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 22:40:58 by bdudley           #+#    #+#             */
/*   Updated: 2018/11/06 17:58:44 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bsq.h"

int	ft_square(char ***map, int n, t_param time_legend)
{
	int i;
	int j;

	j = time_legend.y - 1;
	while (++j < time_legend.y + n)
	{
		i = time_legend.x - 1;
		while (++i < time_legend.x + n)
			if (map[0][j][i] == time_legend.obst)
				return (i);
	}
	j = time_legend.y - 1;
	while (++j < time_legend.y + n)
	{
		i = time_legend.x - 1;
		while (++i < time_legend.x + n)
			map[0][j][i] = time_legend.fill;
	}
	return (-1);
}
