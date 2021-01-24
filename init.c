/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:50:00 by abrun             #+#    #+#             */
/*   Updated: 2021/01/24 15:50:49 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void		init_map(t_map *map, char *tab)
{
	map->map = get_map(tab);
	map->height = (int)get_height(tab);
	map->max_width = get_max_width(tab);
	map->dir = get_dir(*map);
	map->len_pix = 10;
	free(tab);
}

void		init_img(t_img *img, t_param param)
{
	int		bpp;
	int		size_line;
	int		endian;
	void	*image;
	char	*img_data;

	image = mlx_new_image(param.mlx, param.width, param.height);
	img_data = mlx_get_data_addr(image, &bpp, &size_line, &endian);
	img->bpp = bpp;
	img->endian = endian;
	img->size_line = size_line;
	img->data = img_data;
	img->image = image;
}

t_point		get_pos_hero(t_map map)
{
	t_point		pt;

	pt.y = 0;
	while (pt.y < map.height)
	{
		pt.x = 0;
		while (map.map[pt.y][pt.x])
		{
			if (map.map[pt.y][pt.x] == map.dir)
				return (pt);
			pt.x += 1;
		}
		pt.y += 1;
	}
	return (pt);
}

int			get_angle(t_map map)
{
	if (map.dir == 'N')
		return (0);
	else if (map.dir == 'E')
		return (270);
	else if (map.dir == 'S')
		return (180);
	else
		return (90);
}

int			init_param(t_param *param)
{
	param->mlx = mlx_init();
	param->max_w = 1200;
	param->max_h = 1000;
	if (!get_param_cub(param))
		return (0);
	init_wall1_img(&param->walls.wall1, *param);
	init_wall2_img(&param->walls.wall2, *param);
	init_wall3_img(&param->walls.wall3, *param);
	init_wall4_img(&param->walls.wall4, *param);
	init_sprite_img(&param->walls.sprite, *param);
	init_map(&param->map, param->tab);
	init_img(&param->img, *param);
	param->win = mlx_new_window(param->mlx, param->width,
			param->height, "Cub3D");
	init_hero(&param->hero, param->map);
	return (1);
}
