/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:16:44 by abrun             #+#    #+#             */
/*   Updated: 2021/01/21 15:58:41 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

size_t		get_height(char *tab)
{
	size_t height;
	size_t counter;

	height = 0;
	counter = 0;
	while (tab[counter])
	{
		if (tab[counter] == '\n')
			height++;
		counter++;
	}
	return (height);
}

int			get_max_width(char *tab)
{
	int		max;
	int		width;

	max = 0;
	while (*tab)
	{
		width = 0;
		while (*tab != '\n' && *tab)
		{
			width++;
			tab++;
		}
		if (*tab)
			tab++;
		if (max < width)
			max = width;
	}
	return (max);
}

size_t		get_length(char *tab)
{
	size_t len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

int			fill_tabulation(char **map, int i, int *j)
{
	int		counter;

	counter = 4;
	while (counter--)
	{
		map[i][*j] = 32;
		*j += 1;
	}
	return (1);
}
