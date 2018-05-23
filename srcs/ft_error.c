/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:43:53 by mzabalza          #+#    #+#             */
/*   Updated: 2018/05/07 15:08:52 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_matrix(t_map *map, int m, int p)
{
	int i;

	i = 0;
	while (i < (map->nb_row))
	{
		if (m)
			free(map->matrix[i]);
		if (p)
			free(map->p_matrix[i]);
		i++;
	}
	if (m)
		free(map->matrix);
	if (p)
		free(map->p_matrix);
}

void	exit_fdf(int keycode, t_map *map)
{
	if (keycode == 53 || keycode == 50)
	{
		mlx_destroy_image(map->mlx_ptr, map->image);
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		free_matrix(map, 1, 1);
		if (keycode == 50)
			while (1)
				;
		exit(1);
	}
}

int		ft_error(char *str, int rtn_value)
{
	ft_putendl(str);
	return (rtn_value);
}
