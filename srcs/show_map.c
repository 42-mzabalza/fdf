/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 19:11:08 by mzabalza          #+#    #+#             */
/*   Updated: 2018/04/04 19:11:09 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	show_p_matrix(t_map *map, t_point **p_matrix)
{
	int i;
	int j;

	i = 0;
	while (i < map->nb_row)
	{
		j = 0;
		while (j < map->nb_col)
		{
			ft_putnbr(p_matrix[i][j].x);
			ft_putchar(',');
			ft_putnbr(p_matrix[i][j].y);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}


void	show_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->nb_row)
	{
		j = 0;
		while (j < map->nb_col)
		{
			ft_putnbr((map->matrix)[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
