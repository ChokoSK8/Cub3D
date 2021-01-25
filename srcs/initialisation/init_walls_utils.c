/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_walls_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:45:02 by abrun             #+#    #+#             */
/*   Updated: 2021/01/25 19:45:16 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

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
