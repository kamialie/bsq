/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:15:09 by rgyles            #+#    #+#             */
/*   Updated: 2018/11/07 19:23:05 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define BUF_SIZE 1

typedef struct	s_param
{
	int		x;
	int		y;
	char	empty;
	char	obst;
	char	fill;
}				t_param;

void			ft_argument_algorithm(char *file_name);
int				ft_check(char *file_name, t_param *legend);
int				ft_check_map(int fd, t_param **legend, int x, int y);
char			**ft_create_map_matrix(int x, int y, int fd);
void			ft_delete_map(char ***map);
void			ft_error(void);
char			*ft_legend(int fd);
void			ft_print_map(char **map);
void			ft_solution(char ***map, t_param legend);
int				ft_square(char ***map, int n, t_param time_legend);
void			ft_stdin_algorithm(char *file_name);
int				ft_valid_legend(char *first_string, t_param **legend);
char			*ft_write_to_file(void);
#endif
