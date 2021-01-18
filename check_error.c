/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:06:23 by abrun             #+#    #+#             */
/*   Updated: 2021/01/18 15:04:08 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int			last_line_2(char **map, int y)
{
	int		x;

	x = get_length(map[y]) - 1;
	while (x >= 0 && map[y][x] != '1')
		x--;
	if (x == -1)
		return (0);
	while (x > -1)
	{
		if (map[y + 1][x] == '1')
			x = -1;
		else if (map[y][x - 1] == '1')
			x--;
		else
			return (0);
	}
	return (1);
}

int			last_line(char **map, int y)
{
	int		x;

	x = 0;
	while (map[y][x] && map[y][x] != '1')
		x++;
	if (!map[y][x])
		return (0);
	while (map[y][x])
	{
		if (map[y + 1][x] == '1')
			x = get_length(map[y]);
		else if (map[y][x + 1] == '1')
			x++;
		else
			return (0);
	}
	return (last_line_2(map, y));
}

int			left_side_check(char **map, int y)
{
	int		x;

	x = 0;
	while (map[y][x] != '1' && map[y][x])
		x++;
	if (!map[y][x])
		return (0);
	while (map[y][x])
	{
		if (map[y - 1][x] == '1')
			x = get_length(map[y]);
		else if (map[y][x + 1] == '1')
			x++;
		else
			return (0);
	}
	return (1);
}

int			right_side_check(char **map, int y)
{
	int		x;

	x = get_length(map[y]) - 1;
	while (x >= 0 && map[y][x] != '1')
		x--;
	if (x == -1)
		return (0);
	while (x >= 0)
	{
		if (map[y - 1][x] == '1')
			x = -1;
		else if (x > 0 && map[y][x - 1] == '1')
			x--;
		else
			return (0);
	}
	return (1);
}

int			is_surrounded(char **map, int height)
{
	int		y;

	if (!first_and_last(map, height))
		return (0);
	y = 1;
	while (y < height - 1)
	{
		if (!left_side_check(map, y))
			return (0);
		if (!right_side_check(map, y))
			return (0);
		y++;
	}
	return (last_line(map, y - 1));
}
