/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 10:31:32 by abrun             #+#    #+#             */
/*   Updated: 2021/04/02 13:56:38 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

int			check_diag_1_2(t_map map, int y, int x)
{
	int		l;
	int		c;
	int		diag_1;
	int		diag_2;

	diag_1 = 0;
	diag_2 = 0;
	l = x;
	c = y;
	while (c >= 0 && l >= 0 && !diag_1)
	{
		if (map.map[c--][l--] == '1')
			diag_1 = 1;
		else if (map.map[c][l] == 32)
			return (0);
	}
	if (diag_1)
	{
		while (y >= 0 && map.map[y][x] && !diag_2)
			if (map.map[y--][x++] == '1')
				diag_2 = 1;
			else if (map.map[y][x] == 32)
				return (0);
	}
	return (diag_2);
}

int			check_up_down_0(t_map map, int y, int x)
{
	int		up;
	int		c;
	int		down;

	c = y;
	up = 0;
	down = 0;
	while (map.map[c++][x] && !down)
		if (map.map[c][x] == '1')
			down = 1;
		else if (map.map[c][x] == 32)
			return (0);
	if (down)
	{
		while (y >= 0 && !up)
			if (map.map[y--][x] == '1')
				up = 1;
			else if (map.map[y][x] == 32)
				return (0);
	}
	return (up);
}

int			check_right_left_0(t_map map, int y, int x)
{
	int		right;
	int		l;
	int		left;

	l = x;
	right = 0;
	left = 0;
	while (map.map[y][l++] && !right)
		if (map.map[y][l] == '1')
			right = 1;
		else if (map.map[y][l] == 32)
			return (0);
	if (right)
	{
		while (x >= 0 && !left)
			if (map.map[y][x--] == '1')
				left = 1;
			else if (map.map[y][x] == 32)
				return (0);
	}
	return (left);
}

int			is_surrounded(t_map map, int y, int x)
{
	if (check_right_left_0(map, y, x)
		&& check_up_down_0(map, y, x)
		&& check_diag_1_2(map, y, x)
		&& check_diag_3_4(map, y, x))
		return (1);
	return (0);
}

int			check_map(t_map map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (map.map[y][x])
		{
			if (map.map[y][x] == '0')
			{
				if (!is_surrounded(map, y, x))
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
