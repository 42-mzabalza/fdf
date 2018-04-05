/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 20:30:44 by mzabalza          #+#    #+#             */
/*   Updated: 2018/04/02 20:30:59 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	draw_points(t_map *map, t_point **p_matrix)
{
	int i;
	int j;

	i = 0;
	while (i < (map->nb_row))
	{
		j = 0;
		while (j < (map->nb_col))
		{
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, p_matrix[i][j].x, p_matrix[i][j].y, 0xFFFFFF);
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
			p_matrix[i][j].x = (j * map->sx) + map->tx;
			p_matrix[i][j].y = (i * map->sy) + map->ty;
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

int		       draw_map(t_map *map)
{

	t_point **p_matrix;
	//starting points
	map->tx = 20;
	map->ty = 20;
	//lenght of lines
	map->sx = ((WIDTH * 0.4) / (map->nb_col));    // 800/19
	map->sy = ((HEIGHT * 0.4) / (map->nb_row));   // 800/11
	if (!(p_matrix = alloc_point_matrix(map)))
		return (0);
	traslation(map, 50, 50); //como se dice en englis traslacion
	insert_p_matrix(map, p_matrix);
	
	/*
	rotate(map, p_matrix, 30);
	*/
	//ft_putnbr(sin(30 * M_PI / 180));
	//show_p_matrix(map, p_matrix);
	draw_points(map, p_matrix);
	//sleep(10);
	rotate(map, p_matrix, 30 * M_PI / 180);
	draw_points(map, p_matrix);
	return (1);
}