/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_points.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 20:30:44 by mzabalza          #+#    #+#             */
/*   Updated: 2018/05/07 14:49:08 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			ft_new_matrix(t_map *map, t_point **p_matrix)
{
	int	i;
	int	j;

	i = 0;
	while (i < (map->nb_row))
	{
		j = 0;
		while (j < (map->nb_col))
		{
			p_matrix[i][j].x = (j * map->lxy);
			p_matrix[i][j].y = (i * map->lxy);
			p_matrix[i][j].z = map->matrix[i][j] * map->lxy * map->height;
			p_matrix[i][j].y -= (map->nb_row / 2) * map->lxy;
			p_matrix[i][j].x -= (map->nb_col / 2) * map->lxy;
			ft_rotate(map, p_matrix, i, j);
			p_matrix[i][j].y += (map->nb_row / 2) * map->lxy;
			p_matrix[i][j].x += (map->nb_col / 2) * map->lxy;
			p_matrix[i][j].x += map->tx;
			p_matrix[i][j].y += map->ty;
			j++;
		}
		i++;
	}
}

static void		insert_p_matrix(t_map *map, t_point **p_matrix)
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
			p_matrix[i][j].color = select_color(map, p_matrix[i][j].z);
			j++;
		}
		i++;
	}
}

static t_point	**alloc_point_matrix(t_map *map)
{
	t_point **p_matrix;
	int		i;

	if (!(p_matrix = (t_point **)malloc(sizeof(t_point *) * map->nb_row)))
		exit(1);
	i = 0;
	while (i < map->nb_row)
	{
		if (!(p_matrix[i] = (t_point *)malloc(sizeof(t_point) * map->nb_col)))
			exit(1);
		i++;
	}
	return (p_matrix);
}

/*
** char *img_data =  mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
** bpp = 32 -> a pixel is coded on 4 char, worth 8 bits each
** size_line = WIDTH line of pixel, times 4
** endian = 0 or 1, depending oN the architecture of the computer
*/

int				create_points(t_map *map)
{
	if (map->nb_col > map->nb_row)
		map->lxy = ((WIDTH * 0.5) / (map->nb_col));
	else
		map->lxy = ((HEIGHT * 0.5) / (map->nb_row));
	map->p_matrix = alloc_point_matrix(map);
	insert_p_matrix(map, map->p_matrix);
	clear_img_str(map);
	draw_xlines(map, map->p_matrix);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->image, 0, 0);
	draw_info(map);
	return (1);
}
