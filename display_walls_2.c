/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_walls_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:59:35 by abrun             #+#    #+#             */
/*   Updated: 2021/01/19 10:59:56 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

double			get_d(player hero, t_vect pt_a, double counter)
{
	double	dist;

	dist = sqrt(pow(hero.x - pt_a.x, 2) +
			pow(hero.y - pt_a.y, 2)) * cos(convert(counter));
	return (dist);
}

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

void			display_multi_angle(t_param *param, int color)
{
	double	counter;
	double	angle;
	t_vect	pt_a;
	double	n;
	int		n_wall;

	n = 30 / (double)param->width;
	angle = 0;
	n_wall = 0;
	counter = -15;
	while (counter < 15)
	{
		angle = get_angle_right(param->hero.angle, counter);
		if (angle != 0 && angle != 90 && angle != 180 && angle != 270)
			pt_a = get_dist_min(get_pt_h(*param, param->map, angle),
					get_pt_v(*param, param->map, angle), param, angle);
		else
			pt_a = get_pt_a_90(param, angle);
		get_wall_dim(&param->wall, get_d(param->hero, pt_a, counter), *param);
		draw_wall(param->wall, n_wall, param, color);
		n_wall++;
		counter += n;
	}
}
