/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:49:46 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/02/18 11:51:24 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZERS_H
# define INITIALIZERS_H

void	copy_grid(char to[][MAX_SIZE], char from[][MAX_SIZE], int size);
void	initialize_cell_memory(int start_id, t_data *data, int *old_best_size);
void	initialize_grid(char grid[][MAX_SIZE], int size);
void	initialize_int_array(int *arr, int len);
void	initialize_mdata(int start_id, t_data *data, t_mdata *mdata);

#endif
