/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 18:44:20 by mzabalza          #+#    #+#             */
/*   Updated: 2018/04/15 18:44:22 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	color_gradient(t_point p1, t_point p2, float dx, float dy)
{
	int		color_diff;
	float	gradient;

	if (p1.color == p2.color)
		return (0);
	color_diff = ft_abs(p2.color - p1.color);
	gradient = color_diff / (dx + dy); // esto me da problemas
	if (p2.color > p1.color)
		return (gradient);
	return (-gradient);
	// + 257
}

float	select_color(t_map *map, int z)
{
	int int_color;
	int range_len;
	int r;
	int b;
	int g;

	r = 255;
	range_len = map->z_range[1] - map->z_range[0] + 1;
	// if (map->z_range[0] == z)
	// 	return (16711680); //rojo
	z -= map->z_range[0];
	g = (z * 255) / range_len;
	b = (z * 255) / range_len;
	
	int_color = b + (g * 256) + (r * 65536);
	return (int_color);
}

// 0 		noir
// 16777215 blanc

// 16711680 = 255 * 65536 rouge

// 255		 rouge