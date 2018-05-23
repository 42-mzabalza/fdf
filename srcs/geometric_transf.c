/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometric_transf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 19:59:05 by mzabalza          #+#    #+#             */
/*   Updated: 2018/04/16 15:31:55 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		rotate_x(float *y, float *z, float rad)
{
	float y0;
	float z0;

	y0 = *y;
	z0 = *z;
	*y = y0 * cos(rad) - z0 * sin(rad);
	*z = y0 * sin(rad) + z0 * cos(rad);
}

void		rotate_y(float *x, float *z, float rad)
{
	float x0;
	float z0;

	x0 = *x;
	z0 = *z;
	*x = z0 * sin(rad) + x0 * cos(rad);
	*z = z0 * cos(rad) - x0 * sin(rad);
}

void		rotate_z(float *x, float *y, float rad)
{
	float x0;
	float y0;

	x0 = *x;
	y0 = *y;
	*x = x0 * cos(rad) - y0 * sin(rad);
	*y = x0 * sin(rad) + y0 * cos(rad);
}

void		ft_rotate(t_map *map, t_point **p_matrix, int i, int j)
{
	rotate_x(&p_matrix[i][j].y, &p_matrix[i][j].z, map->radx);
	rotate_y(&p_matrix[i][j].x, &p_matrix[i][j].z, map->rady);
	rotate_z(&p_matrix[i][j].x, &p_matrix[i][j].y, map->radz);
}
