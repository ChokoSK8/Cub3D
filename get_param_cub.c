/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param_cub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 09:51:17 by abrun             #+#    #+#             */
/*   Updated: 2021/01/22 12:20:50 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

char		*get_element(int fd)
{
	int		find;
	char	*line;

	find = 0;
	if (!(line = malloc(1000)))
		return (0);
	while (!find)
	{
		if (get_next_line(fd, &line, 5) == -1)
			return (NULL);
		if (*line)
			find = 1;
	}
	return (line);
}

int			fill_param(t_param *param, char *line)
{
	if (ft_strnstr(line, "NO", 5))
		return (get_no_path(param, line));
	else if (ft_strnstr(line, "SO", 5))
		return (get_so_path(param, line));
	else if (ft_strnstr(line, "EA", 5))
		return (get_ea_path(param, line));
	else if (ft_strnstr(line, "WE", 5))
		return (get_we_path(param, line));
	else if (ft_strnchr(line, 'R', 3))
		return (get_resolution(param, line));
	else if (ft_strnchr(line, 'C', 3))
		return (get_color(line, param, 'C'));
	else if (ft_strnchr(line, 'F', 3))
		return (get_color(line, param, 'F'));
	else if (ft_strnchr(line, 'S', 3))
		return (get_sp_path(param, line));
	return (1);
}

int			get_resolution(t_param *param, char *line)
{
	int		counter;
	char	*num;
	int		c;

	counter = 0;
	if (!(num = malloc(20)))
		return (0);
	while (!(ft_isdigit(line[counter])))
		counter++;
	c = 0;
	while (ft_isdigit(line[counter]))
		num[c++] = line[counter++];
	num[c] = 0;
	param->width = ft_atoi(num);
	while (!(ft_isdigit(line[counter])))
		counter++;
	c = 0;
	while (ft_isdigit(line[counter]))
		num[c++] = line[counter++];
	num[c] = 0;
	param->height = ft_atoi(num);
	free(num);
	return (1);
}

int			get_sp_path(t_param *param, char *line)
{
	char	*path;
	int		counter;
	int		c;

	if (!(path = malloc(ft_strlen(line))))
		return (0);
	c = 0;
	while (line[c] && line[c] != '/')
		c++;
	counter = 0;
	while (line[c++] && ft_isprint(line[c]) && !ft_isspace(line[c]))
		path[counter++] = line[c];
	path[counter] = 0;
	if (!(param->SP = ft_strdup(path)))
		return (0);
	free(path);
	return (1);
}

int			get_no_path(t_param *param, char *line)
{
	char	*path;
	int		counter;
	int		c;

	if (!(path = malloc(ft_strlen(line))))
		return (0);
	c = 0;
	while (line[c] && line[c] != '/')
		c++;
	counter = 0;
	while (line[c++] && ft_isprint(line[c]) && !ft_isspace(line[c]))
		path[counter++] = line[c];
	path[counter] = 0;
	if (!(param->NO = ft_strdup(path)))
		return (0);
	free(path);
	return (1);
}

int			get_so_path(t_param *param, char *line)
{
	char	*path;
	int		counter;
	int		c;

	if (!(path = malloc(ft_strlen(line))))
		return (0);
	c = 0;
	while (line[c] && line[c] != '/')
		c++;
	counter = 0;
	while (line[c++] && ft_isprint(line[c]) && !ft_isspace(line[c]))
		path[counter++] = line[c];
	path[counter] = 0;
	if (!(param->SO = ft_strdup(path)))
		return (0);
	free(path);
	return (1);
}
