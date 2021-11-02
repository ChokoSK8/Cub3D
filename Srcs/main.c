/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:55:20 by abrun             #+#    #+#             */
/*   Updated: 2021/10/29 15:18:27 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	destroy_win(int key, t_param *param)
{
	(void)param;
	printf("key : %d\n", key);
	return (1);
}

int	main(int ac, char **av)
{
	t_param		param;

	if (ac < 2 || !check_file(av[1]))
	{
		ft_putstr_fd("Il n'y pas de *.cub passé en argument !\n", 2);
		return (0);
	}
	if (av[1])
		param.cub = av[1];
	if (!init_param(&param))
		return (0);
	param.img_map.image = mlx_new_image(param.mlx,
			param.map.max_width * param.map.len_pix,
			param.map.height * param.map.len_pix);
	param.img_map.data = mlx_get_data_addr(param.img_map.image,
			&param.img_map.bpp, &param.img_map.size_line,
			&param.img_map.endian);
	display_map(param.map, param);
	display_background(param);
	display_multi_angle(&param, 0xFF);
	mlx_put_image_to_window(param.mlx, param.win, param.img.image, 0, 0);
	mlx_hook(param.win, 2, 1L << 0, move_hero, &param);
//	mlx_hook(param.win, 2, 1L << 5, destroy_win, &param);
//	mlx_key_hook(param.win, move_hero, &param);
	mlx_loop(param.mlx);
	return (0);
}