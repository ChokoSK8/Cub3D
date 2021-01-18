/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:05:02 by abrun             #+#    #+#             */
/*   Updated: 2021/01/18 15:31:05 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void		init_hero(player *hero, t_map map)
{
	t_point		pt_h;

	pt_h = get_pos_hero(map);
	hero->angle = get_angle(map);
	hero->x = (pt_h.x + 1) * map.len_pix - map.len_pix / 2;
	hero->y = (pt_h.y + 1) * map.len_pix - map.len_pix / 2;
	hero->len = 2;
	hero->speed = 3;
}

void		init_wall4_img(t_wall *wall, t_param param)
{
	t_img		img;

	img.image = mlx_xpm_file_to_image(param.mlx, "textures/brick.xpm",
			&img.width, &img.height);
	img.data = mlx_get_data_addr(img.image, &img.bpp, &img.size_line,
			&img.endian);
	wall->img.image = mlx_new_image(param.mlx, img.width, img.height);
	wall->img.data = mlx_get_data_addr(wall->img.image, &wall->img.bpp,
			&wall->img.size_line, &wall->img.endian);
	put_xpm_to_final(wall->img.data, img.data, wall->img.size_line, img);
	wall->img.width = img.width;
	wall->img.height = img.height;
}

void		init_wall3_img(t_wall *wall, t_param param)
{
	t_img		img;

	img.image = mlx_xpm_file_to_image(param.mlx, "textures/grass.xpm",
			&img.width, &img.height);
	img.data = mlx_get_data_addr(img.image, &img.bpp, &img.size_line,
			&img.endian);
	wall->img.image = mlx_new_image(param.mlx, img.width, img.height);
	wall->img.data = mlx_get_data_addr(wall->img.image, &wall->img.bpp,
			&wall->img.size_line, &wall->img.endian);
	put_xpm_to_final(wall->img.data, img.data, wall->img.size_line, img);
	wall->img.width = img.width;
	wall->img.height = img.height;
}

void		init_wall2_img(t_wall *wall, t_param param)
{
	t_img		img;

	img.image = mlx_xpm_file_to_image(param.mlx, "textures/stone.xpm",
			&img.width, &img.height);
	img.data = mlx_get_data_addr(img.image, &img.bpp, &img.size_line,
			&img.endian);
	wall->img.image = mlx_new_image(param.mlx, img.width, img.height);
	wall->img.data = mlx_get_data_addr(wall->img.image, &wall->img.bpp,
			&wall->img.size_line, &wall->img.endian);
	put_xpm_to_final(wall->img.data, img.data, wall->img.size_line, img);
	wall->img.width = img.width;
	wall->img.height = img.height;
}

void		init_wall1_img(t_wall *wall, t_param param)
{
	t_img		img;

	img.image = mlx_xpm_file_to_image(param.mlx, "textures/metal.xpm",
			&img.width, &img.height);
	img.data = mlx_get_data_addr(img.image, &img.bpp, &img.size_line,
			&img.endian);
	wall->img.image = mlx_new_image(param.mlx, img.width, img.height);
	wall->img.data = mlx_get_data_addr(wall->img.image, &wall->img.bpp,
			&wall->img.size_line, &wall->img.endian);
	put_xpm_to_final(wall->img.data, img.data, wall->img.size_line, img);
	wall->img.width = img.width;
	wall->img.height = img.height;
}
