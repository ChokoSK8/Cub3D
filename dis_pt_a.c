/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_pt_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 11:23:53 by abrun             #+#    #+#             */
/*   Updated: 2021/01/19 11:24:00 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void				display_pt_a(t_param param, int color, t_vect pt_a)
{
	int		counter;
	int		pos;
	t_point	pt;

	pt.x = round(pt_a.x);
	pt.y = round(pt_a.y);
	counter = 4;
	if ((pt.x >= 0 && pt.x < (param.map.max_width * param.map.len_pix))
			&& (pt.y >= 0 && pt.y < (param.map.height * param.map.len_pix)))
	{
		while (counter--)
		{
			pos = (pt.x * 4) + (param.img_map.size_line * pt.y) + counter;
			color && !counter ? color = -50 : color;
			color && !(counter % 1) ? color = -100 : color;
			color && !(counter % 2) ? color = 20 : color;
			color && !(counter % 3) ? color = 1 : color;
			param.img_map.data[pos] = color;
		}
	}
}
