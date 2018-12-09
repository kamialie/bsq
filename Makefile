# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdudley <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/03 16:06:08 by bdudley           #+#    #+#              #
#    Updated: 2018/11/07 21:19:31 by bdudley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -Wall -Wextra -Werror -c

EXE = bsq

ORC = main.o ft_delete_map.o ft_argument_algorithm.o ft_check.o ft_check_map.o ft_legend.o ft_map_matrix.o ft_print_map.o ft_solution.o ft_square.o ft_stdin_algorithm.o ft_valid_legend.o ft_write_to_file.o

all: $(EXE)

$(EXE): $(ORC)
	gcc -Wall -Wextra -Werror -o $(EXE) $(ORC)

main.o: main.c
	$(CC) main.c 

ft_delete_map.o: source/ft_delete_map.c
	$(CC) source/ft_delete_map.c 

ft_argument_algorithm.o: source/ft_argument_algorithm.c
	$(CC) source/ft_argument_algorithm.c

ft_check.o: source/ft_check.c
	$(CC) source/ft_check.c

ft_check_map.o: source/ft_check_map.c
	$(CC) source/ft_check_map.c

ft_legend.o: source/ft_legend.c
	$(CC) source/ft_legend.c

ft_map_matrix.o: source/ft_map_matrix.c
	$(CC) source/ft_map_matrix.c

ft_print_map.o: source/ft_print_map.c
	$(CC) source/ft_print_map.c

ft_solution.o: source/ft_solution.c
	$(CC) source/ft_solution.c

ft_square.o: source/ft_square.c
	$(CC) source/ft_square.c

ft_stdin_algorithm.o: source/ft_stdin_algorithm.c
	$(CC) source/ft_stdin_algorithm.c

ft_valid_legend.o: source/ft_valid_legend.c
	$(CC) source/ft_valid_legend.c

ft_write_to_file.o: source/ft_write_to_file.c
	$(CC) source/ft_write_to_file.c

clean:
	rm -rf temp_file
	rm -rf $(ORC)

fclean: clean
	rm -rf $(EXE)

re: fclean all
