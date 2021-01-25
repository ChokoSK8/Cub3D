/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:38:09 by abrun             #+#    #+#             */
/*   Updated: 2021/01/25 17:26:54 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void		init_sprite_img(t_wall *wall, t_param param)
{
	t_img		img;

	img.image = mlx_xpm_file_to_image(param.mlx, param.sp,
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

void		init_wall4_img(t_wall *wall, t_param param)
{
	t_img		img;

	img.image = mlx_xpm_file_to_image(param.mlx, param.so,
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

	img.image = mlx_xpm_file_to_image(param.mlx, param.no,
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

	img.image = mlx_xpm_file_to_image(param.mlx, param.we,
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

	img.image = mlx_xpm_file_to_image(param.mlx, param.ea,
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
