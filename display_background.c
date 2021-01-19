/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_background.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:06:40 by abrun             #+#    #+#             */
/*   Updated: 2021/01/19 17:31:19 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void			display_floor_1(char *data, int height, int width, int size_line)
{
	int		x;
	int		y;
	int		pos;

	x = 0;
	while (x < width)
	{
		y = height / 2;
		while (y < height)
		{
			pos = x * 4 + size_line * y;
			data[pos] = 0x60;
			data[pos + 1] = 0xA4;
			data[pos + 2] = 0xF4;
			y++;
		}
		x++;
	}
}

void			display_floor_0(char *data, int height, int width, int size_line)
{
	int		x;
	int		y;
	int		pos;

	x = 0;
	while (x < width)
	{
		y = height / 2;
		while (y < height)
		{
			pos = x * 4 + size_line * y;
			data[pos] = 0x00;
			data[pos + 1] = 0x00;
			data[pos + 2] = 0x00;
			y++;
		}
		x++;
	}
}

void			display_floor(t_param *param, int color)
{
	if (color)
		display_floor_1(param->img.data, param->height, param->width,
			param->img.size_line);
	else
		display_floor_0(param->img.data, param->height, param->width,
			param->img.size_line);
}

void			display_sky_1(char *data, int height, int width, int size_line)
{
	int		x;
	int		y;
	int		pos;

	x = 0;
	while (x < width)
	{
		y = 0;
		while (y < height / 2)
		{
			pos = x * 4 + size_line * y;
			data[pos] = 0x94;
			data[pos + 1] = 0x00;
			data[pos + 2] = 0xD3;
			y++;
		}
		x++;
	}
}

void			display_sky_0(char *data, int height, int width, int size_line)
{
	int		x;
	int		y;
	int		pos;

	x = 0;
	while (x < width)
	{
		y = height / 2;
		while (y < height)
		{
			pos = x * 4 + size_line * y;
			data[pos] = 0x00;
			data[pos + 1] = 0x00;
			data[pos + 2] = 0x00;
			y++;
		}
		x++;
	}
}

void			display_sky(t_param *param, int color)
{
	if (color)
		display_sky_1(param->img.data, param->height, param->width,
			param->img.size_line);
	else
		display_sky_0(param->img.data, param->height, param->width,
			param->img.size_line);
}

void			display_background(t_param *param, int color)
{
	display_sky(param, color);
	display_floor(param, color);
}
