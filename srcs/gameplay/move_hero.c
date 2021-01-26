/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:00:55 by abrun             #+#    #+#             */
/*   Updated: 2021/01/26 15:04:47 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int			move_hero(int key, t_param *param)
{
	display_background(*param);
	change_hero_pos(*param, 0x00);
	if (key == 53)
	{
		mlx_destroy_window(param->mlx, param->win);
		free_param(param);
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

void		move_key_12(t_player *hero, t_img img)
{
	if (!is_wall_12(*hero, img))
	{
		hero->y -= round(hero->speed *
				cos(convert(hero->angle)));
		hero->x -= round(hero->speed *
				sin(convert(hero->angle)));
	}
}

void		move_key_6(t_player *hero, t_img img)
{
	if (!is_wall_6(*hero, img))
	{
		hero->y += round(hero->speed *
				cos(convert(hero->angle)));
		hero->x += round(hero->speed *
				sin(convert(hero->angle)));
	}
}
