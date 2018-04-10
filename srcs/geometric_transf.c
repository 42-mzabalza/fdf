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

void		rotate_y(new_map, new_map->p_matrix, float rad)
{
	int i;
	int j;
	int y0;

	i = 0;
	while (i < (map->nb_col))
	{
		j = 0;
		y0 = map->p_matrix[i][map->nb_row / 2].y;
		while (j < (map->nb_row))
		{
			map->p_matrix[i][j].y = (ft_abs(y0 - map->p_matrix[i][j].y)) * sin(rad);
			j++;
		}
		i++;
	}
}

void		rotate(t_map *map, t_point **p_matrix, float rad)
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

void		add_height(t_map *map, t_point **p_matrix, int h)
{
	int i;
	int j;

	i = 0;
	while (i < (map->nb_row))
	{
		j = 0;
		while (j < (map->nb_col))
		{	
			p_matrix[i][j].y -= p_matrix[i][j].z * h;
			j++;
		}
		i++;
	}
}

void		traslation(t_map *map, int tx, int ty)
{
	int i;
	int j;

	i = 0;
	while (i < (map->nb_row))
	{
		j = 0;
		while (j < (map->nb_col))
		{
			map->p_matrix[i][j].x += tx;
			map->p_matrix[i][j].y += ty;
			j++;
		}
		i++;
	}
}

void		scaling(t_map *map, t_point **p_matrix, int scal)
{
	int i;
	int j;

	i = 0;
	while (i < (map->nb_row))
	{
		j = 0;
		while (j < (map->nb_col))
		{
			//p_matrix[i][j].z = map->matrix[i][j];
			p_matrix[i][j].x += (j * scal);
			p_matrix[i][j].y += (i * scal);
			j++;
		}
		i++;
	}
}
