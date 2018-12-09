/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_to_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:50:01 by rgyles            #+#    #+#             */
/*   Updated: 2018/11/07 21:23:24 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bsq.h"

int		ft_buf_length(char *buf)
{
	int i;

	i = 0;
	while (buf[i] != '\0')
		i++;
	return (i);
}

char	*ft_write_to_file(void)
{
	int		fd;
	int		ret;
	char	buf[4096];

	fd = open("temp_file", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		write(2, "map error\n", 10);
		return (NULL);
	}
	while ((ret = read(0, buf, 4095)))
	{
		if (ret == -1)
		{
			write(2, "map error\n", 10);
			return (NULL);
		}
		buf[ret] = '\0';
		write(fd, buf, ft_buf_length(buf));
	}
	write(fd, "\0", 1);
	if (close(fd) == -1)
		return (NULL);
	return ("temp_file");
}
