/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_walls_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:46:48 by abrun             #+#    #+#             */
/*   Updated: 2021/01/28 09:20:32 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

double			get_angle_right(int angle_h, double counter)
{
	double	angle;

	angle = angle_h + counter;
	if (angle >= 360)
		angle -= 360;
	if (angle < 0)
		angle = 360 + angle;
	return (angle);
}

void			get_wall_dim(t_wall *wall, double dist, t_param param)
{
	wall->width = 1;
	wall->height = (param.height / dist) * 5;
	if (wall->height > param.height)
		wall->height = param.height;
	wall->coeff = wall->height / wall->img.height;
}

double			get_d(t_player hero, t_vect pt_a, double counter)
{
	double	dist;

	dist = sqrt(pow(hero.x - pt_a.x, 2) +
			pow(hero.y - pt_a.y, 2)) * cos(convert(counter));
	return (dist);
}
