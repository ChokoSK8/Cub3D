/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param_cub_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:08:32 by abrun             #+#    #+#             */
/*   Updated: 2021/01/24 16:31:54 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int			get_ea_path(t_param *param, char *line)
{
	char	*path;
	int		counter;
	int		c;

	if (!check_texture("EA", line))
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
	if (!(param->ea = ft_strdup(path)))
		return (0);
	free(path);
	return (1);
}

int			get_we_path(t_param *param, char *line)
{
	char	*path;
	int		counter;
	int		c;

	if (!check_texture("WE", line))
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
	if (!(param->we = ft_strdup(path)))
		return (0);
	free(path);
	return (1);
}

int			is_map(char *line)
{
	while (*line)
	{
		if (ft_isalpha(*line))
			return (0);
		line++;
	}
	return (1);
}

int			fill_tab_map(char *line, int fd, char *tab)
{
	int		done;

	done = 1;
	tab += ft_strcpy(tab, line);
	*tab++ = '\n';
	free(line);
	while (done)
	{
		if ((done = get_next_line(fd, &line, 30)) == -1)
			return (0);
		tab += ft_strcpy(tab, line);
		*tab++ = '\n';
	}
	*(tab - 1) = 0;
	return (1);
}

int			get_param_cub(t_param *param)
{
	int		fd;
	int		done;
	char	*line;

	if (!(param->tab = malloc(10000)))
		return (0);
	done = 0;
	fd = open("map", O_RDONLY);
	while (!done)
	{
		if (!(line = get_element(fd)))
			return (0);
		if (!(fill_param(param, line)))
			return (0);
		done = is_map(line);
		if (!done)
			free(line);
	}
	if (!fill_tab_map(line, fd, param->tab))
		return (0);
	close(fd);
	return (1);
}
