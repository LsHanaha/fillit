/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:49:07 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/02/18 11:58:42 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "initializers.h"

void	copy_grid(char to[][MAX_SIZE], char from[][MAX_SIZE], int size)
{
	int	x;
	int y;

	initialize_grid(to, size);
	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			to[x][y] = from[x][y];
			y++;
		}
		x++;
	}
}

void	initialize_cell_memory(int start_id, t_data *data, int *old_best_size)
{
	int	i;
	int j;

	i = start_id;
	while (i < MAX_SHAPES)
	{
		(data->best_wasted_cells)[i] = MAX_CELLS;
		j = start_id;
		while (j < MAX_SHAPES)
		{
			(data->best_cells)[i][j] = 0;
			j++;
		}
		i++;
	}
	if (old_best_size)
		*old_best_size = data->best_size;
}

void	initialize_grid(char grid[][MAX_SIZE], int size)
{
	int	x;
	int y;

	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			grid[x][y] = 0;
			y++;
		}
		x++;
	}
}

void	initialize_int_array(int *arr, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		arr[i] = 0;
		i++;
	}
}

void	initialize_mdata(int start_id, t_data *data, t_mdata *mdata)
{
	mdata->start_id = start_id;
	initialize_int_array(mdata->cells_array + start_id, data->num - start_id);
	initialize_int_array(mdata->shapes_used + start_id, data->num - start_id);
	copy_grid(mdata->temp_grid, data->grid, data->best_size - 1);
}
