/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:35:41 by abrun             #+#    #+#             */
/*   Updated: 2021/01/25 19:48:08 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

int			is_surrounded(char **map, int height)
{
	int		y;

	y = 1;
	while (y < height - 1)
	{
		if (!left_side_check(map, y))
			return (0);
		if (!right_side_check(map, y))
			return (0);
		y++;
	}
	return (first_last_line(map, height));
}

int			is_pos_hero(char **map)
{
	int		x;
	int		y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'E' ||
				map[y][x] == 'S' || map[y][x] == 'W')
				return (1);
			x++;
		}
		y++;
	}
	ft_putstr_fd("Il n'y a pas de répère pour le héro !\n", 1);
	return (0);
}

int			first_last_line(char **map, int hei)
{
	int		x_b;
	int		x_f;

	if (!get_xs_first(&x_b, &x_f, map))
		return (0);
	if (!xb_to_xf_first(x_b, x_f, map, hei))
		return (0);
	if (!get_xs_last(&x_b, &x_f, map, hei))
		return (0);
	if (!xb_to_xf_last(x_b, x_f, map, hei))
		return (0);
	return (1);
}
