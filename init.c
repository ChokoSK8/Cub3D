/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 13:31:21 by abrun             #+#    #+#             */
/*   Updated: 2021/01/13 14:47:26 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void		init_map(t_map *map)
{
	char	*tab;

	tab = get_tab();
	map->map = get_map(tab);
	map->height = (int)get_height(tab);
	map->max_width = get_max_width(tab);
	map->len_pix = 20;
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

void		init_hero(player *hero, t_map map)
{
	hero->angle = 0;
	hero->x = (map.len_pix * map.max_width) / 2;
	hero->y = (map.len_pix * map.height) / 2;
	hero->len = 7;
}

void		init_param(t_param *param)
{
	param->mlx = mlx_init();
	param->height = 1000;
	param->width = 1000;
	init_map(&param->map);
	init_img(&param->img, *param);
	param->win = mlx_new_window(param->mlx, param->width, param->height, "Cub3D");
	init_hero(&param->hero, param->map);
}
	
