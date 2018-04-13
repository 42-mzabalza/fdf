/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 19:00:46 by mzabalza          #+#    #+#             */
/*   Updated: 2018/04/06 19:00:48 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		draw_points(t_map *map, t_point **p_matrix)
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

static void plot_line(t_map *map, t_point p1, t_point p2)
{
	int x0 = p1.x;
	int y0 = p1.y;
	int x1 = p2.x;
	int y1 = p2.y;
	int color;
	float dx = ft_abs(x1 - x0);
	float sx = x0 < x1 ? 1 : -1;
	float dy = -(ft_abs(y1 - y0));
	float sy = y0 < y1 ? 1 : -1; 
	float err = dx + dy;
	float e2; /* error value e_xy */
 	
 	color =  0xcccccc;
 	if (p1.color == p2.color && p1.color == 0xff0000)
 		color = 0x990000;
 	if (p1.color != p2.color)
 		color = 0x595959;
 	
	while (1)  /* loop */
	{
		//mlx_pixel_put(map->mlx_ptr, map->win_ptr, (int)x0, (int)y0, color);
		fill_img_str(map->img_str, (int)x0, (int)y0, color);
		if (x0 == x1 && y0 == y1) //aqui me podria dar problemas el float
			break;
		e2 = 2 * err;
		if (e2 >= dy)
		{ 
			err += dy;
			x0 += sx; /* e_xy+e_x > 0 */
		} 
		if (e2 <= dx)
		{ 
			err += dx;
			y0 += sy; /* e_xy+e_y < 0 */
		}
	}
}

void		draw_ylines(t_map *map, t_point **p_matrix)
{
	int i;
	int j;

	i = 0;
	while (i < (map->nb_col))
	{
		j = 0;
		while (j < (map->nb_row) - 1)
		{
			plot_line(map, p_matrix[j][i], p_matrix[j + 1][i]);
			j++;
		}
		i++;
	}
}

void		draw_xlines(t_map *map, t_point **p_matrix)
{
	int i;
	int j;

	i = 0;
	while (i < (map->nb_row))
	{
		j = 0;
		while (j < (map->nb_col) - 1)
		{
			plot_line(map, p_matrix[i][j], p_matrix[i][j + 1]);
			j++;
		}
		i++;
	}
}