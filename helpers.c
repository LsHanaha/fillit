/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:48:53 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/02/18 11:59:25 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "generic.h"
#include "solve_helpers.h"

void			clean(t_point point, char grid[][MAX_SIZE], t_shape *shape)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		grid[point.x + shape->points[i].x][point.y + shape->points[i].y] = 0;
		i++;
	}
}

static float	ft_rsqrt(float n, float cur, float precision)
{
	float	temp;

	temp = POW2(cur);
	if (ABS(temp - n) < 0.001)
		return (cur);
	while ((temp = POW2(cur)) < n)
		cur += precision;
	return (temp == n ? cur : ft_rsqrt(n, cur - precision, precision / 10));
}

float			ft_sqrt(float n)
{
	return (ft_rsqrt(n, 1, 1));
}

int				get_size(char grid[][MAX_SIZE], int gridsize)
{
	int	x;
	int y;
	int maxxy;

	x = 0;
	maxxy = 0;
	while (x < gridsize)
	{
		y = 0;
		while (y < gridsize)
		{
			if (grid[x][y])
			{
				if (x > maxxy || y > maxxy)
					maxxy = x > y ? x : y;
			}
			y++;
		}
		x++;
	}
	return (maxxy + 1);
}

void			put(t_point p, int id, char grid[][MAX_SIZE], t_shape *shape)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		grid[p.x + shape->points[i].x][p.y + shape->points[i].y] = 'A' + id;
		i++;
	}
}
