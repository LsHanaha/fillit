/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:48:46 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/02/18 12:24:37 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "generic.h"
#include "initializers.h"
#include "checkers.h"
#include "solve_helpers.h"

int		check_shape(t_point point, char grid[][MAX_SIZE], t_shape *shape)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[point.x + shape->points[i].x][point.y + shape->points[i].y])
			return (0);
		i++;
	}
	return (1);
}

void	check_all_shapes(t_point point, t_shape *shapes,
				t_data *data, t_mdata *mdata)
{
	int i;
	int last_used;

	last_used = -1;
	i = mdata->start_id;
	while (i < data->num)
	{
		if ((point.x + shapes[i].width <= data->best_size - 1) &&
			(point.y + shapes[i].height <= data->best_size - 1) &&
				check_shape(point, data->grid, shapes + i))
		{
			mdata->shapes_used[i] = 1;
			put(point, i, mdata->temp_grid, shapes + i);
			last_used = i;
		}
		i++;
	}
	i = mdata->start_id;
	while (i <= last_used)
	{
		mdata->cells_array[i]++;
		i++;
	}
}

int		check_cells(int start_id, t_data *data, t_mdata *mdata)
{
	int	i;
	int better;

	i = start_id;
	better = 0;
	while (i < data->num)
	{
		if (mdata->cells_array[i] >= data->best_cells[start_id - 1][i])
			better++;
		i++;
	}
	if (!better)
		return (0);
	i = start_id;
	while (i < data->num)
	{
		data->best_cells[start_id - 1][i] = mdata->cells_array[i];
		i++;
	}
	return (1);
}

int		check_memory(int start_id, t_shape *shapes, t_data *data)
{
	int		i;
	t_point	iter;
	t_mdata	mdata;

	if (start_id == data->num)
		return (1);
	initialize_mdata(start_id, data, &mdata);
	iter.x = 0;
	while (iter.x < data->best_size - 1)
	{
		iter.y = 0;
		while (iter.y < data->best_size - 1)
		{
			check_all_shapes(iter, shapes, data, &mdata);
			iter.y++;
		}
		iter.x++;
	}
	i = start_id - 1;
	while (++i < data->num)
		if (!(mdata.cells_array[i]) || !(mdata.shapes_used[i]))
			return (0);
	return (check_wasted_cells(start_id, data, &mdata) &&
			(start_id >= data->num - 5 || !(mdata.wasted_cells) ||
				check_cells(start_id, data, &mdata)));
}

int		check_wasted_cells(int start_id, t_data *data, t_mdata *mdata)
{
	int x;
	int y;
	int	out;

	out = 0;
	x = 0;
	while (x < data->best_size - 1)
	{
		y = 0;
		while (y < data->best_size - 1)
		{
			if (!(mdata->temp_grid[x][y]))
				out++;
			y++;
		}
		x++;
	}
	if ((POW2(data->best_size - 1) - data->num * 4 - out < 0) ||
		(out > data->best_wasted_cells[start_id - 1] + 1))
		return (0);
	mdata->wasted_cells = out;
	data->best_wasted_cells[start_id - 1] = out;
	return (1);
}
