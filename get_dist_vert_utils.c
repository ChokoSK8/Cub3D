/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dist_vert_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:39:16 by abrun             #+#    #+#             */
/*   Updated: 2021/01/18 15:39:49 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int			get_x(t_vect pt, double angle, t_param param)
{
	int		x;

	if (angle > 180)
		x = pt.x / param.map.len_pix;
	else
		x = pt.x / param.map.len_pix - 1;
	return (x);
}
