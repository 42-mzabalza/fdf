/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 20:30:44 by mzabalza          #+#    #+#             */
/*   Updated: 2018/04/02 20:30:59 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		print_line(t_map *map)
{
  t_point *p1;
  t_point *p2;
  int i;
  int j;
  int m;
  int n;
  int x;

  p1 = (t_point *)malloc(sizeof(t_point));
  p2 = (t_point *)malloc(sizeof(t_point));
  p1->x = 500;
  p1->y = 500;
  p2->x = 200;
  p2->y = 100;

  //m = (p2->y - p1->y) / (p2->x - p1->x);
  //HACER UNA FUNCION QUE ME DE LA PENDIENTE DE LA RECTA
  m = 2;
  n = 1;
  i = p1->x;
  j = p1->y;
  while (i <  p1->x + 100)
  {
    x = m;
    while (x--)
    {
      mlx_pixel_put(map->mlx_ptr, map->win_ptr, i, j, 0xFFFFFF);
      i++;
    }
    x = n;
    while (x--)
    {
      mlx_pixel_put(map->mlx_ptr, map->win_ptr, i, j, 0xFFFFFF);
      j++;
    }
    i++;
  }
}
