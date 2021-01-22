/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param_cub_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:27:28 by abrun             #+#    #+#             */
/*   Updated: 2021/01/21 17:32:57 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int			fill_floor(t_param *param, int *tab)
{
	int		counter;

	counter = 0;
	if (!(param->floor = malloc(sizeof(int))))
		return (0);
	while (counter < 3)
	{
		param->floor[counter] = tab[counter];
		counter++;
	}
	return (1);
}

int			fill_roof(t_param *param, int *tab)
{
	int		counter;

	counter = 0;
	if (!(param->roof = malloc(sizeof(int))))
		return (0);
	while (counter < 3)
	{
		param->roof[counter] = tab[counter];
		counter++;
	}
	return (1);
}

int			get_color(char *line, t_param *param, int d)
{
	int		*tab;

	if (!(tab = malloc(sizeof(int))))
		return (0);
	while (*line && !ft_isdigit(*line))
		line++;
	tab[0] = ft_atoi(line);
	while (*line && *line != ',')
		line++;
	tab[1] = ft_atoi(++line);
	while (*line && *line != ',')
		line++;
	tab[2] = ft_atoi(line++);
	if (d == 'F')
	{
		if (!(fill_floor(param, tab)))
			return (0);
	}
	else if (d == 'C')
		if (!(fill_roof(param, tab)))
			return (0);
	free(tab);
	return (1);
}
