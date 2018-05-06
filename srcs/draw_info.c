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

static char *ft_round(int angle)
{
	int tmp;
	char *str_angle;
	char *str_tmp;

	tmp = angle;
	tmp *= (tmp < 0 ? -1 : 1);
	if (tmp % 10 == 9)
	{
		if (angle > 0)
			(angle)++;
		if (angle < 0)
			(angle)--;
	}
	str_tmp = ft_itoa(angle);
	str_angle = ft_strjoin(str_tmp, " grad");
	free(str_tmp);
	return (str_angle);
}

static void	draw_info2(t_map *map, char *str)
{
	str = "ZOOM IN / OUT: ";
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1500, 110, 0x0FFFFFF, str);
	str = "+ / -";
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1700, 110, 0x0FFFFFF, str);
	str = "CHANGE SLOPE: ";
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1500, 130, 0x0FFFFFF, str);
	str = "M, N";
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1700, 130, 0x0FFFFFF, str);
	str = "RESET VALUES: ";
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1500, 150, 0x0FFFFFF, str);
	str = "SPACE";
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1700, 150, 0x0FFFFFF, str);
	str = "QUIT PROGRAM";
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1500, 170, 0x0FFFFFF, str);
	str = "ESC";
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1700, 170, 0x0FFFFFF, str);
}

void		draw_info(t_map *map)
{
	char *str;
	char *angle;

	str = "TRASLATION:";
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1500, 30, 0x0FFFFFF, str);
	str = "UP, DOWN, LEFT, RIGHT";
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1700, 30, 0x0FFFFFF, str);
	str = "X ROTATION: ";
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1500, 50, 0x0FFFFFF, str);
	str = "W, S";
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1700, 50, 0x0FFFFFF, str);
	angle = ft_round((int)(map->radx * 180 / M_PI));
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1800, 50, 0x0FFFFFF, angle);
	free(angle);
	str = "Y ROTATION: ";
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1500, 70, 0x0FFFFFF, str);
	str = "A, D";
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1700, 70, 0x0FFFFFF, str);
	angle = ft_round((int)(map->rady * 180 / M_PI));
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1800, 70, 0x0FFFFFF, angle);
	free(angle);
	str = "Z ROTATION: ";
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1500, 90, 0x0FFFFFF, str);
	str = "R, T";
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1700, 90, 0x0FFFFFF, str);
	angle = ft_round((int)(map->radz * 180 / M_PI));
	mlx_string_put(map->mlx_ptr, map->win_ptr, 1800, 90, 0x0FFFFFF, angle);
	free(angle);
	draw_info2(map, str);
}
