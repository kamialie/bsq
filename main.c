/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:19:31 by rgyles            #+#    #+#             */
/*   Updated: 2018/11/07 16:28:09 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int args, char **argv)
{
	int		i;

	i = 0;
	if (args == 1)
		ft_stdin_algorithm(ft_write_to_file());
	else
		while (++i < args)
		{
			ft_argument_algorithm(argv[i]);
			if (i != args - 1)
				write(1, "\n", 1);
		}
	return (0);
}
