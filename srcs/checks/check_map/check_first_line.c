/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_first_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:45:03 by abrun             #+#    #+#             */
/*   Updated: 2021/01/25 17:22:01 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

int			get_xs_first(int *x_b, int *x_f, char **map)
{
	*x_b = 0;
	while (map[1][*x_b] != '1')
		*x_b += 1;
	while (map[1][*x_b] == '1')
		*x_b += 1;
	*x_b -= 1;
	if (map[0][*x_b] != '1')
	{
		ft_putstr_fd("Il y a un problème sur la première ligne\n", 1);
		return (0);
	}
	*x_f = get_length(map[1]) - 1;
	while (map[1][*x_f] != '1')
		*x_f -= 1;
	while (map[1][*x_f] == '1')
		*x_f -= 1;
	*x_f += 1;
	if (map[0][*x_f] != '1')
	{
		ft_putstr_fd("Il y a un problème sur la première ligne\n", 1);
		return (0);
	}
	return (1);
}

int			xb_to_xf_first(int x_b, int x_f, char **map, int hei)
{
	int		y;
	int		plus;
	int		minus;

	y = 0;
	minus = 1;
	plus = 1;
	while (x_b < x_f)
	{
		if (y > hei - 1)
			return (0);
		else if (map[y][x_b + 1] == '1')
		{
			plus = 1;
			x_b++;
			minus = 1;
		}
		else if (minus && y > 0 && map[y - 1][x_b] == '1')
			ft_minus(&plus, &y);
		else if (plus && y < hei - 1 && map[y + 1][x_b] == '1')
			ft_plus(&minus, &y);
		else
			return (0);
	}
	return (1);
}
