/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_helpers.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:49:53 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/02/18 11:51:49 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_HELPERS_H
# define VALIDATE_HELPERS_H

int		are_duplicates(t_shape a, t_shape b);
int		check_adjacency(t_point shape[]);
int		get_height(t_shape shape);
int		get_width(t_shape shape);

#endif
