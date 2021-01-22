/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dist_hori.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:42:48 by abrun             #+#    #+#             */
/*   Updated: 2021/01/22 12:32:09 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void			get_pt_a(player hero, t_vect *pt_a, t_map map, double angle)
{
	if (angle > 270 || angle < 90)
	{
		pt_a->y = hero.y - (hero.y % map.len_pix);
		if (pt_a->y == hero.y)
			pt_a->y -= map.len_pix;
		if (angle < 90)
			pt_a->x = hero.x + tan(convert(angle)) * (pt_a->y - hero.y);
		else
			pt_a->x = hero.x + tan(convert(angle)) * (pt_a->y - hero.y);
	}
	else
	{
		pt_a->y = hero.y + map.len_pix - (hero.y % map.len_pix);
		if (angle < 180)
			pt_a->x = hero.x - tan(convert(180 - angle)) * (pt_a->y - hero.y);
		else
			pt_a->x = hero.x + tan(convert(angle - 180)) * (pt_a->y - hero.y);
	}
}

void			get_pt_a_hori_90(player hero, t_vect *pt_a, t_map map,
		double angle)
{
	pt_a->x = hero.x;
	if (angle == 0)
	{
		pt_a->y = hero.y - hero.y % map.len_pix;
		if (pt_a->y == hero.y)
			pt_a->y -= map.len_pix;
	}
	else if (angle == 180)
	{
		pt_a->y = hero.y + (map.len_pix - hero.y % map.len_pix);
		if (pt_a->y == hero.y)
			pt_a->y += map.len_pix;
	}
}

void			get_vector(double angle, int len_pix, t_vect *vector)
{
	if (angle > 270 || angle < 90)
	{
		vector->y = -len_pix;
		if (angle < 90)
			vector->x = vector->y * tan(convert(angle));
		else
			vector->x = vector->y * tan(convert(angle));
	}
	else
	{
		vector->y = len_pix;
		if (angle < 180)
			vector->x = -vector->y * tan(convert(180 - angle));
		else
			vector->x = vector->y * tan(convert(angle - 180));
	}
}

int				is_wall_horizontal(t_vect pt, double angle, t_param param)
{
	int		x;
	int		y;

	if (angle > 270 || angle < 90)
		y = (pt.y / param.map.len_pix) - 1;
	else
		y = pt.y / param.map.len_pix;
	if (angle > 180)
		x = pt.x / param.map.len_pix;
	else
		x = pt.x / param.map.len_pix;
	if ((x < param.map.max_width && x >= 0) && (y < param.map.height && y >= 0))
	{
		if (param.map.map[y][x] == '1')
			return (1);
		else if (param.map.map[y][x] == '2')
			return (2);
	}
	else
		return (1);
	return (0);
}

t_vect			get_pt_h(t_param param, t_map map, double angle)
{
	t_vect		pt_a;
	t_vect		vector;
	int			ret;

	if (angle == 0 || angle == 180)
		get_pt_a_hori_90(param.hero, &pt_a, map, angle);
	else
		get_pt_a(param.hero, &pt_a, map, angle);
	get_vector(angle, map.len_pix, &vector);
	while (!(ret = is_wall_horizontal(pt_a, angle, param)))
	{
		pt_a.x += vector.x;
		pt_a.y += vector.y;
	}
	if (ret == 2)
		pt_a.wall = 2;
	else
		pt_a.wall = 1;
	return (pt_a);
}
