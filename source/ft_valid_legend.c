/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_legend.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:29:51 by bdudley           #+#    #+#             */
/*   Updated: 2018/11/06 21:07:21 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bsq.h"

int		ft_strcmp(char *first_string, char *max_int)
{
	int i;

	i = 0;
	while (max_int[i] != '\0')
	{
		if (max_int[i] != first_string[i])
			return (first_string[i] - max_int[i]);
		i++;
	}
	return (0);
}

int		ft_atoi(char *first_string, int i)
{
	int j;
	int y;

	j = 0;
	y = 0;
	if (j == 10)
		if (ft_strcmp(first_string, "2147483647") > 0)
			return (-1);
	if (first_string[j] == '0')
		return (-1);
	while (j < i)
	{
		if (first_string[j] < '0' || first_string[j] > '9')
			return (-1);
		y = y * 10 + (first_string[j] - '0');
		j++;
	}
	return (y);
}

int		ft_valid_legend(char *first_string, t_param **legend)
{
	int i;
	int y;

	i = 0;
	y = 0;
	if (first_string == NULL)
		return (0);
	while (first_string[i] != '\0')
		i++;
	if ((i < 4 || first_string[i] == '0') ||
		(first_string[i - 1] == first_string[i - 2]) ||
		(first_string[i - 1] == first_string[i - 3]) ||
		(first_string[i - 2] == first_string[i - 3]))
		return (0);
	(*legend)->fill = first_string[i - 1];
	(*legend)->obst = first_string[i - 2];
	(*legend)->empty = first_string[i - 3];
	i = i - 3;
	y = ft_atoi(first_string, i);
	if (y < 1)
		return (0);
	(*legend)->y = y;
	return (1);
}
