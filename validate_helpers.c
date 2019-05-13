/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:49:26 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/02/18 12:27:56 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "generic.h"
#include "validate_helpers.h"

int		are_duplicates(t_shape a, t_shape b)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (a.points[i].x != b.points[i].x || a.points[i].y != b.points[i].y)
			return (0);
		i++;
	}
	return (1);
}

int		check_adjacency(t_point shape[])
{
	int	i;
	int j;
	int connections;

	connections = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (j == i)
				continue ;
			if ((shape[i].x == shape[j].x && ABS(shape[i].y - shape[j].y) == 1)
			|| (shape[i].y == shape[j].y && ABS(shape[i].x - shape[j].x) == 1))
				connections++;
		}
	}
	return (connections > 5);
}

int		get_height(t_shape shape)
{
	int	i;
	int max_y;

	i = 0;
	max_y = 0;
	while (i < 4)
	{
		if (shape.points[i].y > max_y)
			max_y = shape.points[i].y;
		i++;
	}
	return (max_y + 1);
}

int		get_width(t_shape shape)
{
	int	i;
	int max_x;

	i = 0;
	max_x = 0;
	while (i < 4)
	{
		if (shape.points[i].x > max_x)
			max_x = shape.points[i].x;
		i++;
	}
	return (max_x + 1);
}
