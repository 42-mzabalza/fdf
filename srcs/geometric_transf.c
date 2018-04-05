/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometric_transf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 19:59:05 by mzabalza          #+#    #+#             */
/*   Updated: 2018/04/04 19:59:09 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		rotate(t_map *map, t_point **p_matrix, double rad)
{
	int i;
	int j;

	i = 0;
	while (i < (map->nb_row))
	{
		j = 0;
		while (j < (map->nb_col))
		{
			p_matrix[i][j].x = p_matrix[i][j].x * cos(rad) - p_matrix[i][j].y * sin(rad);
			p_matrix[i][j].y = p_matrix[i][j].x * sin(rad) + p_matrix[i][j].y * cos(rad);
			j++;
		}
		i++;
	}
}

void		traslation(t_map *map, int tx, int ty)
{
	map->tx = tx;
	map->ty = ty;
}

void		scaling(t_map *map, t_point **matrix)
{

}
