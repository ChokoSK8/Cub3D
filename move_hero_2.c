/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hero_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:38:40 by abrun             #+#    #+#             */
/*   Updated: 2021/01/19 16:38:58 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int			is_wall_around(player hero, t_img img)
{
	int		x;
	int		y;
	int		x_final;
	int		y_final;
	int		pos;

	y = hero.y - 1;
	x_final = hero.x + 1;
	y_final = hero.y + 1;
	while (y < y_final)
	{
		x = hero.x - 1;
		while (x < x_final)
		{
			pos = x * 4 + img.size_line * y;
			if (img.data[pos] == 100 || img.data[pos] == 10)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int			is_wall_12(player hero, t_img img_map)
{
	hero.y -= round(hero.speed * cos(convert(hero.angle)));
	hero.x -= round(hero.speed * sin(convert(hero.angle)));
	if (is_wall_around(hero, img_map))
		return (1);
	return (0);
}

int			is_wall_6(player hero, t_img img_map)
{
	hero.y += round(hero.speed * cos(convert(hero.angle)));
	hero.x += round(hero.speed * sin(convert(hero.angle)));
	if (is_wall_around(hero, img_map))
		return (1);
	return (0);
}
