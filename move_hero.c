/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 14:07:11 by abrun             #+#    #+#             */
/*   Updated: 2021/01/19 17:49:21 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void		move_key_12(player *hero, t_img img)
{
	if (!is_wall_12(*hero, img))
	{
		hero->y -= round(hero->speed *
				cos(convert(hero->angle)));
		hero->x -= round(hero->speed *
				sin(convert(hero->angle)));
	}
}

void		move_key_6(player *hero, t_img img)
{
	if (!is_wall_6(*hero, img))
	{
		hero->y += round(hero->speed *
				cos(convert(hero->angle)));
		hero->x += round(hero->speed *
				sin(convert(hero->angle)));
	}
}

int			move_hero(int key, t_param *param)
{
	display_background(param, 1);
	change_hero_pos(*param, 0x00);
	if (key == 53)
	{
		mlx_destroy_window(param->mlx, param->win);
		param->mlx = NULL;
		return (0);
	}
	if (key == 12)
		move_key_12(&param->hero, param->img_map);
	if (key == 6)
		move_key_6(&param->hero, param->img_map);
	if (key == 2)
		param->hero.angle += 1;
	if (key == 1)
		param->hero.angle -= 1;
	if (param->hero.angle < 0)
		param->hero.angle += 360;
	if (param->hero.angle > 360)
		param->hero.angle %= 360;
	display_multi_angle(param, 0xFF);
	change_hero_pos(*param, 0xFF);
	mlx_put_image_to_window(param->mlx, param->win, param->img.image, 0, 0);
	mlx_put_image_to_window(param->mlx, param->win, param->img_map.image, 0, 0);
	return (1);
}
