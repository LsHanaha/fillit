/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:49:37 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/02/18 11:52:35 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# define ERROR "error"
# define USAGE "usage: ./fillit filename"
# define MAX_SIZE 16
# define MAX_SHAPES 26
# define MAX_CELLS 256

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_shapes_properties
{
	int		squared_n;
	int		total_width;
	int		total_height;
	float	avg_width;
	float	avg_height;
	int		min_size;
	int		max_size;
}				t_properties;

typedef struct	s_solution_data
{
	int		num;
	int		min_size;
	int		best_size;
	int		best_cells[MAX_SHAPES][MAX_SHAPES];
	int		best_wasted_cells[MAX_SHAPES];
	char	grid[MAX_SIZE][MAX_SIZE];
	char	best_grid[MAX_SIZE][MAX_SIZE];
	int		all_duplicates_start_id;
}				t_data;

typedef struct	s_memory_data
{
	int		start_id;
	int		cells_array[MAX_SHAPES];
	int		shapes_used[MAX_SHAPES];
	char	temp_grid[MAX_SIZE][MAX_SIZE];
	int		wasted_cells;
}				t_mdata;

typedef struct	s_shape
{
	t_point	points[4];
	int		width;
	int		height;
	int		duplicate;
	t_point starting_point;
}				t_shape;

int				validate_write(int fd, t_shape *shapes);
void			fill_data(t_shape *shapes, t_data *data);
void			solve(int id, t_shape *shapes, t_data *data);

#endif
