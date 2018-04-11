/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_points.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 20:30:44 by mzabalza          #+#    #+#             */
/*   Updated: 2018/04/02 20:30:59 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			ft_new_matrix(t_map *map, t_point **p_matrix)
{
	int i;
	int j;

	i = 0;
	while (i < (map->nb_row))
	{
		j = 0;
		while (j < (map->nb_col))
		{
			p_matrix[i][j].x = (j * map->lxy);
			p_matrix[i][j].y = (i * map->lxy);
			p_matrix[i][j].z = map->matrix[i][j] * map->lxy * map->height;
			p_matrix[i][j].y -= (map->nb_row / 2) *  map->lxy;
			p_matrix[i][j].x -= (map->nb_col / 2) *  map->lxy;
			rotate_x(&p_matrix[i][j].y, &p_matrix[i][j].z, map->radx);
			rotate_y(&p_matrix[i][j].x, &p_matrix[i][j].z, map->rady);
			rotate_z(&p_matrix[i][j].x, &p_matrix[i][j].y, map->radz);
			p_matrix[i][j].y += (map->nb_row / 2) *  map->lxy;
			p_matrix[i][j].x += (map->nb_col / 2) *  map->lxy;
			p_matrix[i][j].x += map->tx;
			p_matrix[i][j].y += map->ty;
			j++;
		}
		i++;
	}
}

static void	insert_p_matrix(t_map *map, t_point **p_matrix)
{
	int i;
	int j;

	i = 0;
	while (i < (map->nb_row))
	{
		j = 0;
		while (j < (map->nb_col))
		{
			p_matrix[i][j].z = map->matrix[i][j];
			p_matrix[i][j].x = (j * map->lxy) + map->tx;
			p_matrix[i][j].y = (i * map->lxy) + map->ty;
			p_matrix[i][j].i = i;
			p_matrix[i][j].j = j;
			j++;
		}
		i++;
	}
}

static t_point **alloc_point_matrix(t_map *map)
{
	t_point **p_matrix;
	int		i;

	if(!(p_matrix = (t_point **)malloc(sizeof(t_point *) * map->nb_row)))
		return (0);
	i = 0;
	while (i < map->nb_row)
	{
		if (!(p_matrix[i] = (t_point *)malloc(sizeof(t_point) * map->nb_col)))
			return (0);
		i++;
	}
	return (p_matrix);
}

int		       create_points(t_map *map)
{
	t_point **p_matrix;

	if (map->nb_col > map->nb_row)
		map->lxy = ((WIDTH * 0.5) / (map->nb_col));
	else
		map->lxy = ((HEIGHT * 0.5) / (map->nb_row));
	if (!(p_matrix = alloc_point_matrix(map)))
		return (0);
	insert_p_matrix(map, p_matrix);
	map->p_matrix = p_matrix;

	draw_xlines(map, map->p_matrix);
	draw_ylines(map, map->p_matrix);

	return (1);
}