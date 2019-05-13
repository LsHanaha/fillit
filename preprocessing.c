/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:49:13 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/02/18 12:26:06 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "generic.h"
#include "initializers.h"

static void	find_all_duplicates_start_id(t_shape *shapes, t_data *data)
{
	int	id;

	data->all_duplicates_start_id = -1;
	if (data->num < 2)
		return ;
	id = data->num - 2;
	while (id >= 0)
	{
		if (shapes[id].duplicate != id + 1)
			return ;
		data->all_duplicates_start_id = id;
		id--;
	}
}

static void	calculate_sizes(t_shape *shapes, t_data *data, t_properties *pr)
{
	int i;

	pr->min_size = 0;
	pr->total_width = 0;
	pr->total_height = 0;
	i = 0;
	while (i < data->num)
	{
		if (shapes[i].width > pr->min_size)
			pr->min_size = shapes[i].width;
		pr->total_width += shapes[i].width;
		if (shapes[i].height > pr->min_size)
			pr->min_size = shapes[i].height;
		pr->total_height += shapes[i].height;
		i++;
	}
	pr->min_size = MAX((int)CEIL(ft_sqrt(data->num * 4)), pr->min_size);
	pr->avg_width = (float)(pr->total_width) / (float)data->num;
	pr->avg_height = (float)(pr->total_height) / (float)data->num;
	pr->squared_n = (int)CEIL(ft_sqrt(data->num));
	pr->max_size = MAX((int)CEIL(ft_sqrt(MAX(pr->total_width, pr->total_height)
			* MIN(pr->avg_width, pr->avg_height))) + 1,
			(int)(pr->squared_n * MIN(pr->avg_width, pr->avg_height) + 1));
	pr->max_size = MAX(pr->min_size, pr->max_size);
}

void		fill_data(t_shape *shapes, t_data *data)
{
	t_properties pr;

	calculate_sizes(shapes, data, &pr);
	initialize_cell_memory(0, data, NULL);
	data->min_size = pr.min_size;
	data->best_size = pr.max_size + 1;
	find_all_duplicates_start_id(shapes, data);
	initialize_grid(data->grid, data->best_size);
	initialize_grid(data->best_grid, data->best_size);
}
