/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:48:05 by abrun             #+#    #+#             */
/*   Updated: 2021/01/18 15:52:01 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_vect			get_dist_min(t_vect pt_h, t_vect pt_v, t_param *param,
		double angle)
{
	double		dist_h;
	double		dist_v;

	dist_h = sqrt(pow(param->hero.y - pt_h.y, 2) +
			pow(param->hero.x - pt_h.x, 2));
	dist_v = sqrt(pow(param->hero.y - pt_v.y, 2) +
			pow(param->hero.x - pt_v.x, 2));
	if (dist_h < dist_v)
	{
		if (angle < 90 || angle > 270)
			param->wall = param->walls.wall1;
		else
			param->wall = param->walls.wall2;
	}
	else
	{
		if (angle > 0 && angle < 180)
			param->wall = param->walls.wall3;
		else
			param->wall = param->walls.wall4;
	}
	if (dist_h <= dist_v)
		return (pt_h);
	return (pt_v);
}

void			get_wall_dim(t_wall *wall, double dist, t_param param)
{
	wall->width = 1;
	wall->height = (param.height / dist) * 10;
	if (wall->height > param.height)
		wall->height = param.height;
}

void			draw_wall(t_wall wall, int pos_x, t_param *param, int color)
{
	int			y;
	int			pos;
	int			start_y;
	int			y_2;
	int			pos_2;

	y = 0;
	(void)color;
	start_y = (param->height - wall.height) / 2;
	y_2 = 0;
	while (y < wall.height)
	{
		if (color)
		{
			if (!(y_2 % wall.img.height))
				y_2 = 0;
			pos = (pos_x * 4) + (param->img.size_line * (start_y + y));
			pos_2 = ((pos_x % wall.img.width) * 4) +
				(wall.img.size_line * (y % wall.img.height));
			param->img.data[pos] = param->wall.img.data[pos_2];
			param->img.data[pos + 1] = param->wall.img.data[pos_2];
			param->img.data[pos + 2] = param->wall.img.data[pos_2];
			y_2++;
		}
		else
		{
			pos = (pos_x * 4) + (param->img.size_line * (start_y + y));
			param->img.data[pos] = color;
			param->img.data[pos + 1] = color;
			param->img.data[pos + 2] = color;
		}
		y++;
	}
}

t_vect			get_pt_a_90(t_param *param, double angle)
{
	t_vect		pt_a;

	if (angle == 0 || angle == 180)
	{
		if (angle == 0)
			param->wall = param->walls.wall1;
		else
			param->wall = param->walls.wall2;
		pt_a = get_pt_h(*param, param->map, angle);
	}
	else
	{
		if (angle == 90)
			param->wall = param->walls.wall3;
		else
			param->wall = param->walls.wall4;
		pt_a = get_pt_v(*param, param->map, angle);
	}
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

	n = 30 / (double)param->width;
	angle = 0;
	n_wall = 0;
	counter = -15;
	while (counter < 15)
	{
		angle = param->hero.angle + counter;
		if (angle >= 360)
			angle -= 360;
		if (angle < 0)
			angle = 360 + angle;
		if (angle != 0 && angle != 90 && angle != 180 && angle != 270)
			pt_a = get_dist_min(get_pt_h(*param, param->map, angle),
					get_pt_v(*param, param->map, angle), param, angle);
		else
			pt_a = get_pt_a_90(param, angle);
		dist = sqrt(pow(param->hero.x - pt_a.x, 2) +
				pow(param->hero.y - pt_a.y, 2)) * cos(convert(counter));
		get_wall_dim(&param->wall, dist, *param);
		draw_wall(param->wall, n_wall, param, color);
		n_wall++;
		counter += n;
	}
}
