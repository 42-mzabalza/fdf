/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2dmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 18:39:09 by mzabalza          #+#    #+#             */
/*   Updated: 2018/03/29 18:39:12 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Ecuacion de la recta
** nuevo ejes
** x = (i - j)
** y = (-j)
*/

static void	print_linex(int i, int j, t_map *map)
{
  int x;
  int y;
  int scal;

  scal = (map->size) / ((map->x) * 2);
  i = i - j;
  i = i * scal;
  j = j * scal;
  // x = (i - j);
  // y = -j;
  x = 0;
  while (x < scal)
  {
      mlx_pixel_put(map->mlx_ptr, map->win_ptr, i + x, j, 0xFFFFFF);
      //mlx_pixel_put(map->mlx_ptr, map->win_ptr, i, i, 0xFFFFFF);
      x++;
  }
}

static void	print_liney(int i, int j, t_map *map)
{
  int x;
  int y;
  int scal;

  scal = (map->size) / ((map->x) * 2);
  i = i - j;
  i = i * scal;
  j = j * scal;
  // x = (i - j);
  // y = -j;
  x = 0;
	y = 0;
  while (x < scal)
  {
      mlx_pixel_put(map->mlx_ptr, map->win_ptr, i - x, j + y, 0xFFFFFF);
			x++;
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, i - x, j + y, 0xFFFFFF);
      //mlx_pixel_put(map->mlx_ptr, map->win_ptr, i, i, 0xFFFFFF);
      x++;
			y++;
  }
}
void 			print_2dmap(t_map *map)
{
	int i;
	int j;
	ft_putnbr(map->scal);
	j = 0;
	while (j < (map->y))
	{
		i = map->x;
		while (i < map->x + map->x)
		{
			print_linex(i, j, map);
			print_liney(i, j, map);
			i++;
		}
		j++;
	}
}
