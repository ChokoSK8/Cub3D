/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:19:28 by abrun             #+#    #+#             */
/*   Updated: 2021/01/25 10:31:24 by abrun            ###   ########.fr       */
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

int			loop_get_map(char *tab, char **map, int max_width)
{
	int		i;
	int		j;

	i = 0;
	while (*tab)
	{
		j = 0;
		if (!(map[i] = malloc(sizeof(int) * (max_width + 1))))
		{
			ft_printf("Un malloc a échoué !\n");
			return (0);
		}
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
	return (i);
}

char		**get_map(char *tab)
{
	char		**map;
	int			i;
	int			max_width;

	max_width = get_max_width(tab);
	if (!(map = malloc(sizeof(int *) * (get_height(tab) + 1))))
	{
		ft_printf("Un malloc a échoué !\n");
		return (0);
	}
	if (!(i = loop_get_map(tab, map, max_width)))
		return (0);
	map[i] = 0;
	return (map);
}
