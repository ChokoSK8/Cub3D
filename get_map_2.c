/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:19:28 by abrun             #+#    #+#             */
/*   Updated: 2021/01/19 10:19:42 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

size_t		get_width(char *tab)
{
	size_t		counter;
	size_t		width;

	counter = 0;
	width = 0;
	while (tab[counter] && tab[counter] != '\n')
	{
		if (tab[counter] == '\t')
			width += 3;
		counter++;
		width++;
	}
	return (counter);
}

char		**get_map(char *tab)
{
	char		**map;
	int			i;
	int			j;
	int			max_width;

	max_width = get_max_width(tab);
	i = 0;
	map = malloc(sizeof(int *) * (get_height(tab) + 1));
	while (*tab)
	{
		j = 0;
		map[i] = malloc(sizeof(int) * (max_width + 1));
		while (*tab && *tab != '\n')
			if (*tab == '\t')
				tab += fill_tabulation(map, i, &j);
			else
				map[i][j++] = *tab++;
		while (j < max_width)
			map[i][j++] = '0';
		map[i++][j] = 0;
		*tab ? tab++ : tab;
	}
	map[i] = 0;
	return (map);
}
