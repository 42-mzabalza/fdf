/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 19:37:31 by mzabalza          #+#    #+#             */
/*   Updated: 2018/04/16 20:32:49 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	draw_info2(t_map *map)
{
	str = "ZOOM IN / OUT: ";
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1500, 110, 0x0FFFFFF, str);
	str = "+ / -";
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1700, 110, 0x0FFFFFF, str);
	str = "RESET VALUES: ";
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1500, 130, 0x0FFFFFF, str);
	str = "SPACE";
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1700, 130, 0x0FFFFFF, str);
	str = "QUIT PROGRAM";
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1500, 150, 0x0FFFFFF, str);
	str = "ESC";
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1700, 150, 0x0FFFFFF, str);
}

void		draw_info(t_map *map)
{
	char *str;

	str = "TRASLATION:";
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1500, 30, 0x0FFFFFF, str);
	str = "UP, DOWN, LEFT, RIGHT";
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1700, 30, 0x0FFFFFF, str);
	str = "X ROTATION: ";
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1500, 50, 0x0FFFFFF, str);
	str = "W, S";
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1700, 50, 0x0FFFFFF, str);
	str = "Y ROTATION: ";
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1500, 70, 0x0FFFFFF, str);
	str = "A, D";
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1700, 70, 0x0FFFFFF, str);
	str = "Z ROTATION: ";
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1500, 90, 0x0FFFFFF, str);
	str = "R, T";
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1700, 90, 0x0FFFFFF, str);
	draw_info2(map);
}
