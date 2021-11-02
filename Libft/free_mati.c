/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mati.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:43:15 by abrun             #+#    #+#             */
/*   Updated: 2021/10/13 10:32:13 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_mati(int **mati, int m_len)
{
	int		n;

	n = 0;
	while (n < m_len)
	{
		free(mati[n]);
		n++;
	}
	free(mati);
}