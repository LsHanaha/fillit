/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:49:34 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/02/18 11:50:56 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKERS_H
# define CHECKERS_H

int		check_shape(t_point point, char grid[][MAX_SIZE], t_shape *shape);
void	check_all_shapes(t_point point, t_shape *shapes,
				t_data *data, t_mdata *mdata);
int		check_cells(int start_id, t_data *data, t_mdata *mdata);
int		check_memory(int start_id, t_shape *shapes, t_data *data);
int		check_wasted_cells(int start_id, t_data *data, t_mdata *mdata);

#endif
