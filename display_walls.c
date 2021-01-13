/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:48:05 by abrun             #+#    #+#             */
/*   Updated: 2021/01/13 15:55:05 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_vect			get_dist_min(t_vect pt_h, t_vect pt_v, t_param param)
{
	double		dist_h;
	double		dist_v;

	dist_h = sqrt(pow(param.hero.y - pt_h.y, 2) + pow(param.hero.x - pt_h.x, 2));
	dist_v = sqrt(pow(param.hero.y - pt_v.y, 2) + pow(param.hero.x - pt_v.x, 2));
	if (dist_h <= dist_v)
		return (pt_h);
	return (pt_v);
}

void			get_wall_dim(t_wall *wall, double dist, t_param param)
{
	wall->width = 1;
	wall->height = param.height / dist;
}

void			draw_wall(t_wall wall, int pos_x, t_param *param, int color)
{
	int		y;
	int		pos;
	int		start_y;

	y = 0;
	start_y = (param->height - wall.height) / 2;
	while (y < wall.height)
	{
		pos = (pos_x * 4) + (param->img.size_line * (start_y + y));
		param->img.data[pos] = color;
		param->img.data[pos] = color;
		param->img.data[pos] = color;
		y++;
	}
}

//display_map 
void				display_pt_a(t_param param, int color, t_vect pt_a)
{
	int		counter;
	int		pos;
	t_point	pt;

	pt.x = round(pt_a.x);
	pt.y = round(pt_a.y);
	counter = 4;
	if ((pt.x >= 0 && pt.x < (param.map.max_width * param.map.len_pix)) && (pt.y >= 0 && pt.y < (param.map.height * param.map.len_pix)))
	{
		while (counter--)
		{
			pos = (pt.x * 4) + (param.img_map.size_line * pt.y) + counter;
			color && !counter ? color = -50 : color;
			color && !(counter % 1) ? color = -100 : color;
			color && !(counter % 2) ? color = 20 : color;
			color && !(counter % 3) ? color = 1 : color;
			param.img_map.data[pos] = color;
		}
	}
}

t_vect			get_pt_a_90(t_param param, double angle)
{
	t_vect		pt_a;

	if (angle == 0 || angle == 180)
		pt_a = get_pt_h(param, param.map, angle);
	else
		pt_a = get_pt_v(param, param.map, angle);
	return (pt_a);
}

void			display_multi_angle(t_param *param, int color)
{
	double	counter;
	double	angle;
	double	dist;
	t_vect	pt_a;
	double	n;
	int		n_wall;

	n = 0.02;
	angle = 0;
	n_wall = 0;
	counter = -10;
	while (counter < 10)
	{
		angle = param->hero.angle + counter;
		if (angle != 0 && angle != 90 && angle != 180 && angle != 270)
			pt_a = get_dist_min(get_pt_h(*param, param->map, angle), get_pt_v(*param, param->map, angle), *param); 
		else
			pt_a = get_pt_a_90(*param, angle);
		display_pt_a(*param, 100, pt_a);
		dist = sqrt(pow(param->hero.x - pt_a.x, 2) + pow(param->hero.y - pt_a.y, 2)) * cos(convert_deg_in_rad(counter));
		get_wall_dim(&param->wall, dist, *param);
		draw_wall(param->wall, n_wall, param, color);
		n_wall++;
		counter += n;
	}
}
