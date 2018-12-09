/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_legend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:28:47 by bdudley           #+#    #+#             */
/*   Updated: 2018/11/07 17:59:51 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bsq.h"

char	*ft_legend(int fd)
{
	int		ret;
	int		count;
	char	buf[BUF_SIZE];
	char	*first_string;

	count = 0;
	if (!(first_string = (char *)malloc(sizeof(*first_string) * 14)))
		return (NULL);
	while ((ret = read(fd, buf, BUF_SIZE)) && buf[0] != '\n')
	{
		if (ret == -1 || count > 13)
			return (NULL);
		first_string[count++] = buf[0];
	}
	first_string[count] = '\0';
	return (first_string);
}
