/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sides.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:46:28 by abrun             #+#    #+#             */
/*   Updated: 2021/01/27 14:41:46 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

int			left_side_check(char **map, int y)
{
	int		x;

	x = 0;
	while (map[y][x] != '1' && map[y][x])
		x++;
	if (!map[y][x])
		return (0);
	while (map[y][x])
	{
		printf("(%d, %d)\n", y, x);
		if (map[y - 1][x] == '1')
			x = get_length(map[y]);
		else if (map[y][x + 1] == '1')
			x++;
		else
			return (0);
	}
	printf("hey1\n");
	return (1);
}

int			right_side_check(char **map, int y)
{
	int		x;

	x = get_length(map[y]) - 1;
	while (x >= 0 && map[y][x] != '1')
		x--;
	if (x == -1)
		return (0);
	while (x >= 0)
	{
		if (map[y - 1][x] == '1')
			x = -1;
		else if (x > 0 && map[y][x - 1] == '1')
			x--;
		else
			return (0);
	}
	printf("hey2\n");
	return (1);
}
