/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_img_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:21:34 by mzabalza          #+#    #+#             */
/*   Updated: 2018/04/16 15:26:50 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	clear_img_str(t_map *map)
{
	int i;

	i = 0;
	while (i < WIDTH * HEIGHT)
	{
		map->img_str[i] = BLACK;
		i++;
	}
}

void	fill_img_str(int *img_str, int x, int y, int color)
{
	int i;

	if (x >= WIDTH || x <= 0 || y <= 0 || y >= HEIGHT)
		return ;
	i = x + y * WIDTH;
	img_str[i] = color;
}
