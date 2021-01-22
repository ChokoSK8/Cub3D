/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 13:27:21 by abrun             #+#    #+#             */
/*   Updated: 2021/01/21 16:56:52 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int			main(int ac, char **av)
{
	t_param		param;
	t_img		map_img;
	int			run;

	(void)av;
	(void)ac;
	run = 1;
	if (!init_param(&param))
		return (0);
	map_img.image = mlx_new_image(param.mlx, param.map.max_width *
		param.map.len_pix, param.map.height * param.map.len_pix);
	map_img.data = mlx_get_data_addr(map_img.image, &map_img.bpp,
		&map_img.size_line, &map_img.endian);
	param.img_map = map_img;
	if (!is_surrounded(param.map.map, param.map.height))
		return (0);
	display_map(param.map, param);
	display_background(param);
	display_multi_angle(&param, 0xFF);
	change_hero_pos(param, 0xFF);
	mlx_put_image_to_window(param.mlx, param.win, param.img.image, 0, 0);
	mlx_put_image_to_window(param.mlx, param.win, param.img_map.image, 0, 0);
	mlx_hook(param.win, 2, 1L << 0, move_hero, &param);
	mlx_loop(param.mlx);
	return (1);
}
