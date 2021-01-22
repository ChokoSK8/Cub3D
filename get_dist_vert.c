/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dist_vert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:45:37 by abrun             #+#    #+#             */
/*   Updated: 2021/01/22 12:32:01 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void		get_pt_a_vert(player hero, t_vect *pt_a, t_map map, double angle)
{
	if (angle > 180)
	{
		pt_a->x = hero.x + map.len_pix - (hero.x % map.len_pix);
		if (pt_a->x == hero.x)
			pt_a->x += map.len_pix;
		if (angle > 270)
			pt_a->y = hero.y - tan(convert(angle - 270)) * (pt_a->x - hero.x);
		else
			pt_a->y = hero.y + tan(convert(270 - angle)) * (pt_a->x - hero.x);
	}
	else
	{
		pt_a->x = hero.x - (hero.x % map.len_pix);
		if (pt_a->x == hero.x)
			pt_a->x -= map.len_pix;
		if (angle < 90)
			pt_a->y = hero.y - tan(convert(angle + 90)) * (pt_a->x - hero.x);
		else
			pt_a->y = hero.y - tan(convert(angle - 90)) * (pt_a->x - hero.x);
	}
}

void		get_pt_a_vert_90(player hero, t_vect *pt_a, t_map map, double angle)
{
	pt_a->y = hero.y;
	if (angle == 90)
	{
		pt_a->x = hero.x - hero.x % map.len_pix;
		if (pt_a->x == hero.x)
			pt_a->x -= map.len_pix;
	}
	else if (angle == 270)
	{
		pt_a->x = hero.x + (map.len_pix - hero.x % map.len_pix);
		if (pt_a->x == hero.x)
			pt_a->x += map.len_pix;
	}
}

void		get_vector_vert(double angle, int len_pix, t_vect *vector)
{
	if (angle > 180)
	{
		vector->x = len_pix;
		if (angle > 270)
			vector->y = -tan(convert(angle - 270)) * len_pix;
		else
			vector->y = tan(convert(270 - angle)) * len_pix;
	}
	else
	{
		vector->x = -len_pix;
		if (angle < 90)
			vector->y = tan(convert(angle + 90)) * len_pix;
		else
			vector->y = tan(convert(angle - 90)) * len_pix;
	}
}

int			is_wall_vert(t_vect pt, double angle, t_param param)
{
	int		x;
	int		y;
	int		pt_y;

	pt_y = (int)pt.y;
	x = get_x(pt, angle, param);
	if (angle < 90 || angle > 270)
	{
		if (!(pt.y - pt_y) && !((int)pt.y % param.map.len_pix))
			y = pt.y / param.map.len_pix - 1;
		else
			y = pt.y / param.map.len_pix;
	}
	else
		y = pt.y / param.map.len_pix;
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

t_vect		get_pt_v(t_param param, t_map map, double angle)
{
	t_vect		pt_a;
	t_vect		vector;
	int			ret;

	if (angle == 270 || angle == 90)
		get_pt_a_vert_90(param.hero, &pt_a, map, angle);
	else
		get_pt_a_vert(param.hero, &pt_a, map, angle);
	get_vector_vert(angle, map.len_pix, &vector);
	while (!(ret = is_wall_vert(pt_a, angle, param)))
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
