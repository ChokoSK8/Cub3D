/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 14:01:58 by abrun             #+#    #+#             */
/*   Updated: 2021/01/22 14:28:17 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int			real_last_line(char **map, int hei)
{
	int		x_b;
	int		x_f;
	int		y;

	x_b = 0;
	while (map[hei - 2][x_b] != '1')
		x_b++;
	while (map[hei - 2][x_b] == '1')
		x_b++;
	if (map[hei - 1][--x_b] != '1')
		return (0);
	x_f = get_length(map[hei - 2]);
	while (map[hei - 2][x_f] != '1')
		x_f--;
	while (map[hei - 2][x_f] == '1')
		x_f--;
	if (map[hei - 1][++x_f] != '1')
		return (0);
	y = hei - 1;
	while (x_b < x_f)
	{
		if (y < 1)
			return (0);
		else if (map[y][x_b] == '1')
			x_b++;
		else if (y < hei - 1 && map[y + 1][--x_b] == '1')
			y++;
		else if (map[y - 1][--x_b] == '1')
			y--;
		else
			return (0);
		printf("(%d, %d)\n", y, x_b);
	}
	return (1);
}

int			first_and_last(char **map, int height)
{
	int		x;
	int		y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (map[y][x] && map[y][x] != '1')
			x++;
		if (!map[y][x])
			return (0);
		while (map[y][x])
		{
			if (map[y][x] != '1')
			{
				while (map[y][x] && map[y][x] != '1')
					x++;
				if (map[y][x])
					return (0);
			}
			x++;
		}
		y += height - 1;
	}
	return (1);
}
