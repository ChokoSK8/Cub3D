/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:08:13 by abrun             #+#    #+#             */
/*   Updated: 2021/01/19 09:56:47 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

double		convert(double degre)
{
	double rad;

	rad = degre / 57.2958;
	return (rad);
}

void		put_xpm_to_final(char *data_final, char *data,
		int size_line, t_img img)
{
	int		x;
	int		y;
	int		pos;

	y = 0;
	while (y < img.height)
	{
		x = 0;
		while (x < img.width)
		{
			pos = x * 4 + size_line * y;
			data_final[pos] = data[pos];
			data_final[pos + 1] = data[pos + 1];
			data_final[pos + 2] = data[pos + 2];
			data_final[pos + 3] = data[pos + 3];
			x++;
		}
		y++;
	}
}
