/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_hero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:59:56 by abrun             #+#    #+#             */
/*   Updated: 2021/01/25 17:23:57 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void		change_hero_pos(t_param param, int color)
{
	int		x;
	int		y;
	int		counter;
	int		pos;

	y = 0;
	while (y < param.hero.len)
	{
		x = 0;
		while (x < param.hero.len)
		{
			counter = 0;
			while (counter < 4)
			{
				pos = (param.hero.x - x) * 4 + (param.img_map.size_line *
				(param.hero.y - y)) + counter;
				color ? color = -10 : color;
				param.img_map.data[pos] = color;
				counter++;
			}
			x++;
		}
		y++;
	}
}
