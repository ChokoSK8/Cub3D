/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param_res.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:07:56 by abrun             #+#    #+#             */
/*   Updated: 2021/01/25 10:14:15 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int			get_n(char *line)
{
	char	*num;
	int		c;
	int		n;

	c = 0;
	if (!(num = malloc(6)))
	{
		ft_printf("Un malloc a échoué ! \n");
		return (-1);
	}
	while (ft_isdigit(*line) && c < 6)
		num[c++] = *line++;
	num[c] = 0;
	n = ft_atoi(num);
	free(num);
	return (n);
}

int			fill_w_h(t_param *param, char *line, int id)
{
	int			n;

	n = get_n(line);
	if (n == -1)
		return (0);
	if (id == 'w')
	{
		if (n > param->max_w)
			param->width = param->max_w;
		else
			param->width = n;
	}
	else
	{
		if (n > param->max_h)
			param->height = param->max_h;
		else
			param->height = n;
	}
	return (1);
}

int			get_resolution(t_param *param, char *line)
{
	if (!(check_resolution('R', line)))
		return (0);
	while (!(ft_isdigit(*line)))
		line++;
	if (!fill_w_h(param, line, 'w'))
		return (0);
	while (ft_isdigit(*line))
		line++;
	while (!ft_isdigit(*line))
		line++;
	if (!fill_w_h(param, line, 'h'))
		return (0);
	return (1);
}
