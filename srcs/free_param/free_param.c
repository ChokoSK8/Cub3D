/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:23:18 by abrun             #+#    #+#             */
/*   Updated: 2021/01/26 16:50:52 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void		free_param(t_param *param)
{
	int		counter;

	counter = 0;
	free(param->no);
	free(param->sp);
	free(param->so);
	free(param->ea);
	free(param->we);
	free(param->floor);
	free(param->roof);
	free(param->img.data);
	free(param->img.image);
	free(param->walls.wall1.img.data);
	free(param->walls.wall2.img.data);
	free(param->walls.wall3.img.data);
	free(param->walls.wall4.img.data);
	free(param->walls.sprite.img.data);
	free(param->walls.sprite.img.image);
	free(param->walls.wall1.img.image);
	free(param->walls.wall2.img.image);
	free(param->walls.wall3.img.image);
	free(param->walls.wall4.img.image);
	while (param->map.map[counter])
		free(param->map.map[counter++]);
	free(param->map.map);
	free(param->img_map.data);
	free(param->img_map.image);
//	free(param);
//	free(param->checks);
//	free(param->tab);
//	free(param->cub);
}
