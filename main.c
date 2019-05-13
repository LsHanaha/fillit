/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:49:10 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/02/18 11:53:29 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "fillit.h"

static void	display_error(char *text, int fd, int status)
{
	ft_putendl_fd(text, fd);
	exit(status);
}

static void	print_result(char grid[][MAX_SIZE], int grid_size)
{
	int x;
	int y;

	y = 0;
	while (y < grid_size)
	{
		x = 0;
		while (x < grid_size)
		{
			ft_putchar(grid[x][y] ? grid[x][y] : '.');
			x++;
		}
		y++;
		ft_putchar('\n');
	}
}

int			main(int argc, char **argv)
{
	int		fd;
	t_shape	shapes[26];
	t_data	data;

	if (argc != 2)
		display_error(USAGE, 1, 0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1 || !(data.num = validate_write(fd, shapes)) || close(fd) == -1)
		display_error(ERROR, 1, 0);
	fill_data(shapes, &data);
	solve(0, shapes, &data);
	print_result(data.best_grid, data.best_size);
	return (0);
}
