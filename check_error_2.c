/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 14:01:58 by abrun             #+#    #+#             */
/*   Updated: 2021/01/24 14:09:43 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int			get_xs(int *x_b, int *x_f, char **map, int hei)
{
	*x_b = 0;
	while (map[hei - 2][*x_b] != '1')
		*x_b += 1;
	while (map[hei - 2][*x_b] == '1')
		*x_b += 1;
	*x_b -= 1;
	if (map[hei - 1][*x_b] != '1')
		return (0);
	*x_f = get_length(map[hei - 2]);
	while (map[hei - 2][*x_f] != '1')
		*x_f -= 1;
	while (*x_f >= 0 && map[hei - 2][*x_f] == '1')
		*x_f -= 1;
	*x_f += 1;
	if (map[hei - 1][*x_f] != '1')
		return (0);
	return (1);
}

void		ft_minus(int *plus, int *y)
{
	*y -= 1;
	*plus = 0;
}

void		ft_plus(int *minus, int *y)
{
	*y += 1;
	*minus = 0;
}

int			xb_to_xf(int x_b, int x_f, char **map, int hei)
{
	int		y;
	int		plus;
	int		minus;

	y = hei - 1;
	minus = 1;
	plus = 1;
	while (x_b < x_f)
	{
		if (y < 1)
			return (0);
		else if (map[y][x_b + 1] == '1')
		{
			plus = 1;
			x_b++;
			minus = 1;
		}
		else if (minus && y > 1 && map[y - 1][x_b] == '1')
			ft_minus(&plus, &y);
		else if (plus && y < hei - 1 && map[y + 1][x_b] == '1')
			ft_plus(&minus, &y);
		else
			return (0);
	}
	return (1);
}

int			real_last_line(char **map, int hei)
{
	int		x_b;
	int		x_f;

	if (!get_xs(&x_b, &x_f, map, hei))
		return (0);
	if (!xb_to_xf(x_b, x_f, map, hei))
		return (0);
	return (1);
}
