/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:02:13 by abrun             #+#    #+#             */
/*   Updated: 2021/01/27 17:13:52 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

void		get_pt_start(t_point *pt, char **map)
{
	int		y;

	y = pt->y;
	while (map[y][pt->x] != '1')
		y--;
	pt->y = y;
}

int			is_0_around(t_point pt, char **map, int max_w, int hei)
{
	if ((pt.x - 1 >= 0 && map[pt.y][pt.x - 1] == '0')
			|| (pt.x + 1 < max_w && map[pt.y][pt.x + 1] == '0')
			|| (pt.y - 1 >= 0 && map[pt.y - 1][pt.x] == '0')
			|| (pt.y + 1 < hei && map[pt.y + 1][pt.x] == '0')
			|| (pt.y + 1 < hei && pt.x + 1 < max_w && map[pt.y + 1][pt.x + 1] == '0')
			|| (pt.y - 1 >= 0 && pt.x + 1 < max_w && map[pt.y - 1][pt.x + 1] == '0')
			|| (pt.y - 1 >= 0 && pt.x - 1 >= 0  && map[pt.y - 1][pt.x - 1] == '0')
			|| (pt.y + 1 < hei && pt.x - 1 >= 0 && map[pt.y + 1][pt.x - 1] == '0'))
		return (1);
	else
		return (0);
}

int			go_left(t_point pt, char **map, int max_w, int hei)
{
	pt.x -= 1;
	if (pt.x >= 0 && map[pt.y][pt.x] == '1')
		if (is_0_around(pt, map, max_w, hei))
			return (1);
	return (0);
}

int			go_down(t_point pt, char **map, int max_w, int hei)
{
	pt.y += 1;
	if (pt.y < hei && map[pt.y][pt.x] == '1')
		if (is_0_around(pt, map, max_w, hei))
			return (1);
	return (0);
}

int			go_right(t_point pt, char **map, int max_w, int hei)
{
	pt.x += 1;
	if (pt.x < max_w && map[pt.y][pt.x] == '1')
		if (is_0_around(pt, map, max_w, hei))
			return (1);
	return (0);
}

int			go_up(t_point pt, char **map, int max_w, int hei)
{
	pt.y -= 1;
	if (pt.y >= 0 && map[pt.y][pt.x] == '1')
		if (is_0_around(pt, map, max_w, hei))
			return (1);
	return (0);
}

int			check_around(t_point pt, t_map map)
{
	t_point		pt_start;
	int			right;
	int			left;
	int			down;
	int			up;

	right = 1;
	left = 1;
	up = 1;
	down = 1;
	pt_start.x = pt.x;
	pt_start.y = pt.y;
	if (go_left(pt, map.map, map.max_width, map.height))
		pt.x -= 1;
	else if (go_down(pt, map.map, map.max_width, map.height))
		pt.y += 1;
	else if (go_right(pt, map.map, map.max_width, map.height))
		pt.x += 1;
	else if (go_up(pt, map.map, map.max_width, map.height))
		pt.y -= 1;
	else
		return (0);
	while (pt.x != pt_start.x || pt.y != pt_start.y)
	{
		if (left && go_left(pt, map.map, map.max_width, map.height))
		{
			up = 1;
			down = 1;
			right = 0;
			pt.x -= 1;
		}
		else if (down && go_down(pt, map.map, map.max_width, map.height))
		{
			up = 0;
			right = 1;
			left = 1;
			pt.y += 1;
		}
		else if (right && go_right(pt, map.map, map.max_width, map.height))
		{
			up = 1;
			down = 1;
			left = 0;
			pt.x += 1;
		}
		else if (up && go_up(pt, map.map, map.max_width, map.height))
		{
			down = 0;
			right = 1;
			left = 1;
			pt.y -= 1;
		}
		else
			return (0);
	}
	return (1);
}

t_point		get_hero(char **map)
{
	t_point p;

	p.y = 0;
	while (map[p.y])
	{
		p.x = 0;
		while (map[p.y][p.x])
		{
			if (map[p.y][p.x] >= 'A' && map[p.y][p.x] <= 'Z')
				return (p);
			p.x += 1;
		}
		p.y += 1;
	}
	return (p);
}


int			is_surrounded_2(t_map map)
{
	t_point		pt;

	pt = get_hero(map.map);
	get_pt_start(&pt, map.map);
	if (!check_around(pt, map))
		return (0);
	return (1);
}
