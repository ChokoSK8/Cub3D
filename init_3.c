/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:11:05 by abrun             #+#    #+#             */
/*   Updated: 2021/01/24 16:21:36 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int			get_dir(t_map map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (map.map[y][x])
		{
			if (map.map[y][x] >= 'A' && map.map[y][x] <= 'Z')
				return (map.map[y][x]);
			x++;
		}
		y++;
	}
	return (0);
}

void		init_hero(t_player *hero, t_map map)
{
	t_point		pt_h;

	pt_h = get_pos_hero(map);
	hero->angle = get_angle(map);
	hero->x = (pt_h.x + 1) * map.len_pix - map.len_pix / 2;
	hero->y = (pt_h.y + 1) * map.len_pix - map.len_pix / 2;
	hero->len = 2;
	hero->speed = 3;
}
