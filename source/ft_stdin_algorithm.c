/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin_algorithm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:54:23 by bdudley           #+#    #+#             */
/*   Updated: 2018/11/07 18:08:22 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bsq.h"

void	ft_stdin_algorithm(char *file_name)
{
	int		fd;
	char	**map;
	t_param	legend;

	if (ft_check(file_name, &legend))
	{
		if ((fd = open(file_name, O_RDONLY)) == -1)
		{
			write(2, "map error\n", 10);
			return ;
		}
		map = ft_create_map_matrix(legend.x, legend.y, fd);
		ft_solution(&map, legend);
		ft_print_map(map);
		ft_delete_map(&map);
	}
	else
		write(2, "map error\n", 10);
}
