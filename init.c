/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 13:31:21 by abrun             #+#    #+#             */
/*   Updated: 2021/01/15 10:56:46 by abrun            ###   ########.fr       */
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

void		init_map(t_map *map)
{
	char	*tab;

	tab = get_tab();
	map->map = get_map(tab);
	map->height = (int)get_height(tab);
	map->max_width = get_max_width(tab);
	map->dir = get_dir(*map);
	map->len_pix = 40;
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

void		init_param(t_param *param)
{
	param->mlx = mlx_init();
	param->height = 700;
	param->width = 700;
	init_map(&param->map);
	init_img(&param->img, *param);
	param->win = mlx_new_window(param->mlx, param->width, param->height, "Cub3D");
	init_hero(&param->hero, param->map);
}
