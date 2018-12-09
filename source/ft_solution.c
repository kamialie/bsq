/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 21:26:42 by bdudley           #+#    #+#             */
/*   Updated: 2018/11/06 17:58:32 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bsq.h"

void	ft_solution(char ***map, t_param legend)
{
	t_param	time_legend;
	int		n;

	time_legend = legend;
	n = (legend.x < legend.y) ? legend.x + 1 : legend.y + 1;
	while (--n > 0)
	{
		time_legend.y = -1;
		while (++time_legend.y < legend.y)
		{
			if (time_legend.y + n > legend.y)
				break ;
			time_legend.x = -1;
			while (++time_legend.x < legend.x)
			{
				if (time_legend.x + n > legend.x)
					break ;
				if (ft_square(&(*map), n, time_legend) != -1)
					time_legend.x = ft_square(&(*map), n, time_legend);
				else
					return ;
			}
		}
	}
}
