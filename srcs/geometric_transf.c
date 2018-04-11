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


// void		rotate_x(t_map *map, t_point **p_matrix, float rad)
// {
// 	int i;
// 	int j;
// 	float y0;
// 	float z0;
// 	int y;
// 	int y1;

// 	i = 0;
// 	while (i < (map->nb_row))
// 	{
// 		j = 0;
// 		while (j < (map->nb_col))
// 		{
// 			y0 = map->p_matrix[i][j].y;
// 			z0 = map->p_matrix[i][j].z;
// 			y = map->p_matrix[map->nb_row / 2][0].y;
// 			y1 = (y - y0) * cos(rad) - z0 * sin(rad);
// 			map->p_matrix[i][j].z = (y - y0) * sin(rad) + z0 * cos(rad);
// 			// ft_putnbr(map->p_matrix[i][j].z);
// 			// ft_putchar('\n');
// 			map->p_matrix[i][j].y = (y - y1);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void		rotate_y(t_map *map, t_point **p_matrix, float rad)
// {
// 	int i;
// 	int j;
// 	float x0;
// 	float z0;
// 	int x;
// 	int x1;

// 	i = 0;
// 	while (i < (map->nb_row))
// 	{
// 		j = 0;
// 		while (j < (map->nb_col))
// 		{
// 			x0 = map->p_matrix[i][j].x;
// 			z0 = map->p_matrix[i][j].z;
// 			x = map->p_matrix[i][0].x; //EJE DE GIRO
// 			x1 = z0 * sin(rad) + (x0 - x) * cos(rad);
// 			map->p_matrix[i][j].z = z0 * cos(rad) - (x0 - x) * sin(rad);
// 			// ft_putnbr(map->p_matrix[i][j].z);
// 			// ft_putchar('\n');
// 			map->p_matrix[i][j].x = (x + x1);
// 			j++;
// 		}
// 		i++;
// 	}
// }