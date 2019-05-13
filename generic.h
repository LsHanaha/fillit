/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:49:43 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/02/18 11:49:44 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERIC_H
# define GENERIC_H
# define ABS(X) (X < 0 ? -(X) : X)
# define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
# define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
# define CEIL(X) ((X) - (int)(X) == 0 ? (X) : (X + 1))
# define POW2(X) ((X) * (X))

float	ft_sqrt(float n);

#endif
