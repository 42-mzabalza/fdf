/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_perspective.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 11:53:51 by mzabalza          #+#    #+#             */
/*   Updated: 2018/05/07 14:48:04 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	add_perspective(t_map *map, t_point **p_m)
{
	int i;
	int j;

	i = 0;
	while (i < (map->nb_row))
	{
		j = 0;
		while (j < (map->nb_col))
		{
			p_m[i][j].x = (p_m[i][j].x * 2000) / (3000 - p_m[i][j].z);
			p_m[i][j].y = (p_m[i][j].y * 2000) / (3000 - p_m[i][j].z);
			j++;
		}
		i++;
	}
}
