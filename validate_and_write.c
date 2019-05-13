/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_and_write.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:49:23 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/02/18 13:24:54 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "generic.h"
#include "validate_helpers.h"

static void	adjust_topleft(t_point shape[], int points_found,
		t_point *topleft, t_point *iter)
{
	int	i;

	topleft->y = topleft->y < 0 ? iter->y : topleft->y;
	topleft->x = topleft->x < 0 ? iter->x : topleft->x;
	if (iter->x < topleft->x)
	{
		i = -1;
		while (++i < points_found)
			shape[i].x += topleft->x - iter->x;
		topleft->x = iter->x;
	}
	shape[points_found].x = iter->x - topleft->x;
	shape[points_found].y = iter->y - topleft->y;
}

static int	validate_tetrimino(int fd, t_point shapes[][4], int id)
{
	char	*line;
	t_point	topleft;
	t_point	iter;
	int		points_found;

	iter.y = -1;
	points_found = 0;
	topleft.x = -1;
	topleft.y = -1;
	while (++(iter.y) < 4)
	{
		if (ft_gnl(fd, &line) <= 0 || ft_strlen(line) != 4)
			return (0);
		iter.x = -1;
		while (++(iter.x) < 4)
		{
			if (line[iter.x] == '.')
				continue ;
			if (line[iter.x] != '#' || points_found == 4)
				return (0);
			adjust_topleft(shapes[id], points_found++, &topleft, &iter);
		}
		free(line);
	}
	return (points_found == 4 && check_adjacency(shapes[id]));
}

void		mark_duplicates(int num, t_shape *shapes)
{
	int	i;
	int j;

	i = 0;
	while (i < num)
	{
		shapes[i].duplicate = 0;
		j = i + 1;
		while (j < num)
		{
			if (are_duplicates(shapes[i], shapes[j]))
			{
				shapes[i].duplicate = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

static int	write_shapes(int num, t_point raw_shapes[][4], t_shape *shapes)
{
	int i;
	int j;

	i = 0;
	while (i < num)
	{
		j = 0;
		while (j < 4)
		{
			shapes[i].points[j].x = raw_shapes[i][j].x;
			shapes[i].points[j].y = raw_shapes[i][j].y;
			j++;
		}
		shapes[i].width = get_width(shapes[i]);
		shapes[i].height = get_height(shapes[i]);
		shapes[i].starting_point.x = 0;
		shapes[i].starting_point.y = 0;
		i++;
	}
	mark_duplicates(num, shapes);
	return (num);
}

int			validate_write(int fd, t_shape *shapes)
{
	int		num;
	char	*line;
	int		status;
	t_point	raw_shapes[26][4];

	num = 0;
	while (validate_tetrimino(fd, raw_shapes, num))
	{
		++num;
		status = ft_gnl(fd, &line);
		if (!status)
			return (write_shapes(num, raw_shapes, shapes));
		if (status == -1)
			return (0);
		if (ft_strlen(line))
		{
			free(line);
			return (0);
		}
		free(line);
		if (num >= 26)
			return (0);
	}
	return (0);
}
