/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param_cub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 09:51:17 by abrun             #+#    #+#             */
/*   Updated: 2021/01/21 10:53:42 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int			get_resolution(t_param *param, int fd)
{
	char	*line;
	int		counter;
	int		find;
	char	*num;

	find = 0;
	while (!find)
	{
		counter = 0;
		if (get_next_line(fd, &line, 5) == -1)
			return (0);
		while (line[counter] && line[counter] != 'R')
			counter++;
		if (line[counter] == 'R')
			find = 1;
	}
	if (!(num = malloc(20)))
		return (0);
	while (!(ft_isdigit(line[counter])))
		counter++;
	find = 0;
	while (ft_isdigit(line[counter]))
		num[find++] = line[counter++];
	num[find] = 0;
	param->width = ft_atoi(num);
	while (!(ft_isdigit(line[counter])))
		counter++;
	find = 0;
	while (ft_isdigit(line[counter]))
		num[find++] = line[counter++];
	num[find] = 0;
	param->height = ft_atoi(num);
	free(num);
	free(line);
}

int			get_NOpath(t_param *param, int fd)
{
	int		find;
	char	*path;
	char	to_find[2];

	to_find = "NO";
	find = 0;
	while (!find)
	{
		


int			get_param_cub(t_param *param)
{
	int		fd;

	fd = open("map", O_RDONLY);
	if (!(get_resolution(param, fd)))
		return (0);
	close(fd);
	return (1);
}
