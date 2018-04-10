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

// static void	draw_xline(t_map *map, t_point p1, t_point p2)
// {
// 	int		dx;
// 	int		dy;
// 	int 	d_err;
// 	float 	r_err;
// 	int		x;
// 	int		y;

// 	dx = p2.x - p1.x;
// 	dy = p2.y - p1.y;
// 	d_err = ft_abs(dx / dy);
// 	r_err = 0.0;
// 	y = p2.y;
// 	x = p1.x;
// 	r_err = 0.5;
// 	while (x < p2.x)
// 	{
// 		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, 0xFFFFFF);
// 		r_err += d_err;
// 		 while (r_err ≥ 0.5)
// 		 {
// 		 	 y += sign(deltay) * 1;
//              r_err -= 1.0;
// 		 }
            

// 	}
// }

static void plot_line(t_map *map, t_point p1, t_point p2)
{
	int colour;
	int dx =  ft_abs(p2.x - p1.x);
	int sx = p1.x < p2.x ? 1 : -1;
	int dy = -abs (p2.y - p1.y);
	int sy = p1.y < p2.y ? 1 : -1; 
	int err = dx + dy;
	int e2; /* error value e_xy */
 	
 	colour = 0x999999;
 	if (p1.z || p2.z)
 		colour = 0x444444;
 	if (p1.z && p2.z)
 		colour = 0xCC0000;
	while (1)  /* loop */
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, p1.x, p1.y, colour);
		if (p1.x == p2.x && p1.y == p2.y) 
			break;
		e2 = 2 * err;
		if (e2 >= dy)
		{ 
			err += dy;
			p1.x += sx; /* e_xy+e_x > 0 */
		} 
		if (e2 <= dx)
		{ 
			err += dx;
			p1.y += sy; /* e_xy+e_y < 0 */
		}
	}
}

// static void	draw_xline(t_map *map, t_point p1, t_point p2)
// {
// 	double	i;
// 	double	slope;
// 	double 	j;

// 	slope = (p2.y - p1.y) / (p2.x - p1.x);
// 	i = p1.x;
// 	while (i < p2.x)
// 	{
// 		j = slope * (i - p2.x) + p2.y;
// 		mlx_pixel_put(map->mlx_ptr, map->win_ptr, i, j, 0xFFFFFF);
// 		i++;
// 	}

// }

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
