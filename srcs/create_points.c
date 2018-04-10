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
			p_matrix[i][j].x = (j * map->lx);
			p_matrix[i][j].y = (i * map->ly);
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
	//starting points
	map->tx = 20;
	map->ty = 20;
	//lenght of lines
	map->lx = ((WIDTH * 0.4) / (map->nb_col));    // 800/19
	map->ly = ((HEIGHT * 0.5) / (map->nb_row));   // 800/11
	if (!(p_matrix = alloc_point_matrix(map)))
		return (0);
	insert_p_matrix(map, p_matrix);
	map->p_matrix = p_matrix;
	traslation(map, WIDTH * 0.3, HEIGHT * 0.2); //como se dice en englis traslacion


	//show_p_matrix(map, p_matrix);
	//draw_points(map, p_matrix);
	//mlx_clear_window(map->mlx_ptr, map->win_ptr);
	//sleep(10);
	//rotate(map, map->p_matrix, 30 * M_PI / 180);

	//add_height(map, map->p_matrix, -5);
	//draw_points(map, p_matrix);
	draw_xlines(map, map->p_matrix);
	draw_ylines(map, map->p_matrix);
	//draw_ylines(map, p_matrix);
	return (1);
}