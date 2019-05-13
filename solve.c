/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:49:19 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/02/18 12:28:13 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "generic.h"
#include "initializers.h"
#include "checkers.h"
#include "solve_helpers.h"

static void	save_result(char grid[][MAX_SIZE], t_data *data)
{
	data->best_size = get_size(grid, data->best_size);
	copy_grid(data->best_grid, grid, data->best_size);
}

static void	write_starting_point(t_shape *shape, t_point point)
{
	shape->starting_point.x = point.x;
	shape->starting_point.y = point.y;
}

static int	can_go_deeper(int id, t_shape *shapes, t_data *data, t_point iter)
{
	int	went_deeper;

	if (!check_shape(iter, data->grid, shapes + id))
		return (0);
	went_deeper = 0;
	put(iter, id, data->grid, shapes + id);
	if (get_size(data->grid, data->best_size) < data->best_size
		&& (data->all_duplicates_start_id == id + 1 ||
			check_memory(id + 1, shapes, data)))
	{
		if (shapes[id].duplicate)
			write_starting_point(shapes + shapes[id].duplicate, iter);
		solve(id + 1, shapes, data);
		went_deeper = 1;
	}
	clean(iter, data->grid, shapes + id);
	return (went_deeper);
}

void		solve(int id, t_shape *shapes, t_data *data)
{
	t_point	iter;
	int		first_iteration;
	int		old_best_size;

	if (id == data->num)
		return (save_result(data->grid, data));
	if (data->best_size <= data->min_size)
		return ;
	old_best_size = data->best_size;
	first_iteration = 1;
	iter.y = shapes[id].starting_point.y;
	while (iter.y <= data->best_size - 1 - shapes[id].height)
	{
		iter.x = first_iteration ? shapes[id].starting_point.x : 0;
		while (iter.x <= data->best_size - 1 - shapes[id].width)
		{
			if (can_go_deeper(id, shapes, data, iter)
					&& data->best_size < old_best_size)
				initialize_cell_memory(id, data, &old_best_size);
			iter.x++;
		}
		iter.y++;
		first_iteration = 0;
	}
}
