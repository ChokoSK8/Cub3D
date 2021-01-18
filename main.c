/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 13:27:21 by abrun             #+#    #+#             */
/*   Updated: 2021/01/18 15:52:47 by abrun            ###   ########.fr       */
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

	y = hero.y - 3;
	x_final = hero.x + 3;
	y_final = hero.y + 3;
	while (y < y_final)
	{
		x = hero.x - 3;
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

int			move_hero(int key, t_param *param)
{
	display_multi_angle(param, 0x00);
	change_hero_pos(*param, 0x00);
	if (key == 12)
	{
		if (!is_wall_12(param->hero, param->img_map))
		{
			param->hero.y -= round(param->hero.speed *
					cos(convert(param->hero.angle)));
			param->hero.x -= round(param->hero.speed *
					sin(convert(param->hero.angle)));
		}
	}
	if (key == 6)
	{
		if (!is_wall_6(param->hero, param->img_map))
		{
			param->hero.y += round(param->hero.speed *
					cos(convert(param->hero.angle)));
			param->hero.x += round(param->hero.speed *
					sin(convert(param->hero.angle)));
		}
	}
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

int			main()
{
	t_param		param;

	init_param(&param);

	//Display_map
	t_img		map_img;
	//param.win_map = mlx_new_window(param.mlx, param.map.max_width * param.map.len_pix, param.map.height * param.map.len_pix, "map_hero");
	map_img.image = mlx_new_image(param.mlx, param.map.max_width * param.map.len_pix, param.map.height * param.map.len_pix);
	map_img.data = mlx_get_data_addr(map_img.image, &map_img.bpp, &map_img.size_line, &map_img.endian);
	param.img_map = map_img;
	if (!is_surrounded(param.map.map, param.map.height))
		return (0);
	display_map(param.map, param);

	display_multi_angle(&param, 0xFF);
	change_hero_pos(param, 0xFF);
	mlx_put_image_to_window(param.mlx, param.win, param.img.image, 0, 0);
	mlx_put_image_to_window(param.mlx, param.win, param.img_map.image, 0, 0);
	mlx_hook(param.win, 2, 1L<<0, move_hero, &param);
	mlx_loop(param.mlx);
}
