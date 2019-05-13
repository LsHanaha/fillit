/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_helpers.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:49:49 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/02/18 11:51:08 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_HELPERS_H
# define SOLVE_HELPERS_H

void	clean(t_point point, char grid[][MAX_SIZE], t_shape *shape);
int		get_size(char grid[][MAX_SIZE], int gridsize);
void	put(t_point p, int id, char grid[][MAX_SIZE], t_shape *shape);

#endif
