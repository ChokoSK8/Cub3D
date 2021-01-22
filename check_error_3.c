/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:14:58 by abrun             #+#    #+#             */
/*   Updated: 2021/01/22 18:15:23 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int			first_and_last(char **map, int height)
{
	int		x;
	int		y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (map[y][x] && map[y][x] != '1')
			x++;
		if (!map[y][x])
			return (0);
		while (map[y][x])
		{
			if (map[y][x] != '1')
			{
				while (map[y][x] && map[y][x] != '1')
					x++;
				if (map[y][x])
					return (0);
			}
			x++;
		}
		y += height - 1;
	}
	return (1);
}
