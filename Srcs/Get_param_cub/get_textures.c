/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:56:59 by abrun             #+#    #+#             */
/*   Updated: 2021/11/02 10:55:26 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	get_so_path(t_param *param, char *line)
{
	char	*path;
	int		counter;
	int		c;

	if (!check_texture("SO", line, param->checks[1]))
		return (0);
	path = malloc(ft_strlen(line));
	if (!path)
		return (0);
	c = 0;
	while (line[c] && line[c] != '/')
		c++;
	counter = 0;
	while (line[c++] && ft_isprint(line[c]) && !ft_isspace(line[c]))
		path[counter++] = line[c];
	path[counter] = 0;
	param->so = ft_strdup(path);
	if (!param->so)
	{
		free(path);
		ft_putstr_fd("Error\nUn malloc a échoué !\n", 2);
		return (0);
	}
	free(path);
	return (2);
}

int	get_ea_path(t_param *param, char *line)
{
	char	*path;
	int		counter;
	int		c;

	if (!check_texture("EA", line, param->checks[2]))
		return (0);
	path = malloc(ft_strlen(line));
	if (!path)
		return (0);
	c = 0;
	while (line[c] && line[c] != '/')
		c++;
	counter = 0;
	while (line[c++] && ft_isprint(line[c]) && !ft_isspace(line[c]))
		path[counter++] = line[c];
	path[counter] = 0;
	param->ea = ft_strdup(path);
	if (!param->ea)
	{
		free(path);
		ft_putstr_fd("Error\nUn malloc a échoué !\n", 2);
		return (0);
	}
	free(path);
	return (3);
}

int	get_we_path(t_param *param, char *line)
{
	char	*path;
	int		counter;
	int		c;

	if (!check_texture("WE", line, param->checks[3]))
		return (0);
	path = malloc(ft_strlen(line));
	if (!path)
		return (0);
	c = 0;
	while (line[c] && line[c] != '/')
		c++;
	counter = 0;
	while (line[c++] && ft_isprint(line[c]) && !ft_isspace(line[c]))
		path[counter++] = line[c];
	path[counter] = 0;
	param->we = ft_strdup(path);
	if (!param->we)
	{
		free(path);
		ft_putstr_fd("Error\nUn malloc a échoué !\n", 2);
		return (0);
	}
	free(path);
	return (4);
}

int	get_sp_path(t_param *param, char *line)
{
	char	*path;
	int		counter;
	int		c;

	if (!check_texture("S", line, param->checks[7]))
		return (0);
	path = malloc(ft_strlen(line));
	if (!path)
		return (0);
	c = 0;
	while (line[c] && line[c] != '/')
		c++;
	counter = 0;
	while (line[c++] && ft_isprint(line[c]) && !ft_isspace(line[c]))
		path[counter++] = line[c];
	path[counter] = 0;
	param->sp = ft_strdup(path);
	if (!param->sp)
	{
		free(path);
		ft_putstr_fd("Error\nUn malloc a échoué !\n", 2);
		return (0);
	}
	free(path);
	return (8);
}

int	get_no_path(t_param *param, char *line)
{
	char	*path;
	int		counter;
	int		c;

	if (!check_texture("NO", line, param->checks[0]))
		return (0);
	path = malloc(ft_strlen(line));
	if (!path)
		return (0);
	c = 0;
	while (line[c] && line[c] != '/')
		c++;
	counter = 0;
	while (line[c++] && ft_isprint(line[c]) && !ft_isspace(line[c]))
		path[counter++] = line[c];
	path[counter] = 0;
	param->no = ft_strdup(path);
	if (!param->no)
	{
		free(path);
		ft_putstr_fd("Error\nUn malloc a échoué !\n", 2);
		return (0);
	}
	free(path);
	return (1);
}
