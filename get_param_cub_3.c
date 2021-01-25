/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param_cub_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:27:28 by abrun             #+#    #+#             */
/*   Updated: 2021/01/25 10:19:33 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int			get_so_path(t_param *param, char *line)
{
	char	*path;
	int		counter;
	int		c;

	if (!check_texture("SO", line))
		return (0);
	if (!(path = malloc(ft_strlen(line))))
		return (0);
	c = 0;
	while (line[c] && line[c] != '/')
		c++;
	counter = 0;
	while (line[c++] && ft_isprint(line[c]) && !ft_isspace(line[c]))
		path[counter++] = line[c];
	path[counter] = 0;
	if (!(param->so = ft_strdup(path)))
		return (0);
	free(path);
	return (1);
}

int			fill_floor(t_param *param, int *tab)
{
	int		counter;

	counter = 0;
	if (!(param->floor = malloc(sizeof(int))))
	{
		ft_printf("Un malloc a échoué ! \n");
		return (0);
	}
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
	{
		ft_printf("Un malloc a échoué ! \n");
		return (0);
	}
	while (counter < 3)
	{
		param->roof[counter] = tab[counter];
		counter++;
	}
	return (1);
}

int			*get_color_fill_tab(char *line)
{
	int		*tab;

	if (!(tab = malloc(sizeof(int) * 3)))
	{
		ft_printf("Un malloc a échoué ! \n");
		return (0);
	}
	while (*line && !ft_isdigit(*line))
		line++;
	tab[0] = ft_atoi(line);
	while (*line && *line != ',')
		line++;
	tab[1] = ft_atoi(++line);
	while (*line && *line != ',')
		line++;
	tab[2] = ft_atoi(line++);
	return (tab);
}


int			get_color(char *line, t_param *param, int d)
{
	int		*tab;

	if (!check_color(d, line))
		return (0);
	if (!(tab = get_color_fill_tab(line)))
		return (0);
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
