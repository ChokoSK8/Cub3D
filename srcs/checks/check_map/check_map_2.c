/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 10:31:32 by abrun             #+#    #+#             */
/*   Updated: 2021/04/02 13:56:38 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

int			is_pos_hero(char **map)
{
	int		x;
	int		y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'E' ||
				map[y][x] == 'S' || map[y][x] == 'W')
				return (1);
			x++;
		}
		y++;
	}
	ft_putstr_fd("Il n'y a pas de répère pour le héro !\n", 1);
	return (0);
}

int			is_valid_k(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == 32)
		return (1);
	else if (c == 'N' || c == 'W' || c == 'S' || c == 'E')
		return (2);
	return (0);
}

int			check_cases_loop(char **map)
{
	int	y;
	int	x;
	int	ret;
	int	hero;

	y = 0;
	hero = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!(ret = is_valid_k(map[y][x])))
			{
				printf("Il y a un caractère invalide en (%d, %d) !\n", y, x);
				return (-1);
			}
			if (ret == 2)
				hero++;
			x++;
		}
		y++;
	}
	return (hero);
}

int			check_cases(char **map)
{
	int		hero;

	hero = check_cases_loop(map);
	if (hero == -1)
		return (0);
	else if (hero > 1)
	{
		printf("Il y a deux repères pour le hero !\n");
		return (0);
	}
	else if (hero == 0)
	{
		printf("Il n'y a pas de repère pour le héro !\n");
		return (0);
	}
	return (1);
}

int			check_diag_3_4(t_map map, int y, int x)
{
	int		l;
	int		c;
	int		diag_3;
	int		diag_4;

	diag_3 = 0;
	diag_4 = 0;
	l = x;
	c = y;
	while (!diag_3 && c < map.height && l >= 0)
	{
		if (map.map[c++][l--] == '1')
			diag_3 = 1;
		else if (map.map[c][l] == 32)
			return (0);
	}
	if (diag_3)
	{
		while (y < map.height && map.map[y][x] && !diag_4)
			if (map.map[y++][x++] == '1')
				diag_4 = 1;
			else if (map.map[y][x] == 32)
				return (0);
	}
	return (diag_4);
}
