/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 19:00:46 by mzabalza          #+#    #+#             */
/*   Updated: 2018/04/16 15:20:21 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		draw_points(t_map *map, t_point **p_mtrx)
{
	int i;
	int j;

	i = 0;
	while (i < (map->nb_row))
	{
		j = 0;
		while (j < (map->nb_col))
		{
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, p_mtrx[i][j].x
					, p_mtrx[i][j].y, WHITE);
			j++;
		}
		i++;
	}
}

static void	init_plot_values(t_breshm_line *line, t_point p1, t_point p2)
{
	line->p0[0] = p1.x;
	line->p0[1] = p1.y;
	line->p1[0] = p2.x;
	line->p1[1] = p2.y;
	line->dxy[0] = ft_abs(line->p1[0] - line->p0[0]);
	line->dxy[1] = -ft_abs(line->p1[1] - line->p0[1]);
	line->sxy[0] = line->p0[0] < line->p1[0] ? 1 : -1;
	line->sxy[1] = line->p0[1] < line->p1[1] ? 1 : -1;
	line->gradient = color_gradient(p1, p2, line->dxy[0], -(line->dxy[1]));
	line->color = p1.color;
}

static void	plot_line(t_map *map, t_point p1, t_point p2)
{
	t_breshm_line	line;
	float			err;
	float			e2;

	init_plot_values(&line, p1, p2);
	err = line.dxy[0] + line.dxy[1];
	while (1)
	{
		fill_img_str(map->img_str, line.p0[0], line.p0[1], (int)line.color);
		if ((int)line.p0[0] == line.p1[0] && line.p0[1] == line.p1[1])
			break ;
		e2 = 2 * err;
		if (e2 >= line.dxy[1])
		{
			err += line.dxy[1];
			line.p0[0] += (int)line.sxy[0];
			line.color += line.gradient;
		}
		if (e2 <= line.dxy[0])
		{
			err += line.dxy[0];
			line.p0[1] += (int)line.sxy[1];
			line.color += line.gradient;
		}
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
		while (j < (map->nb_col))
		{
			if (j < map->nb_col - 1)
				plot_line(map, p_matrix[i][j], p_matrix[i][j + 1]);
			if (i < map->nb_row - 1)
				plot_line(map, p_matrix[i][j], p_matrix[i + 1][j]);
			j++;
		}
		i++;
	}
}
