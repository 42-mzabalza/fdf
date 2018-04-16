/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 19:27:58 by mzabalza          #+#    #+#             */
/*   Updated: 2018/04/16 20:33:03 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		free_matrix(t_map *map, int m, int p)
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

static void	reset_matrix(t_map *map)
{
	map->height = 1;
	map->radx = 0.0;
	map->rady = 0.0;
	map->radz = 0.0;
	map->tx = WIDTH * 0.3;
	map->ty = HEIGHT * 0.2;
	map->line_size = WIDTH * 4;
	map->lxy = ((WIDTH * 0.5) / (map->nb_col));
}

static void	key_action(int keycode, t_map *map)
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
	keycode == 49 ? reset_matrix(map) : 0;
	map->tx += (keycode == 124 ? 50 : 0);
	map->tx += (keycode == 123 ? -50 : 0);
	map->ty += (keycode == 126 ? -50 : 0);
	map->ty += (keycode == 125 ? 50 : 0);
	map->height += (keycode == 46 ? 0.1 : 0);
	map->height += (keycode == 45 ? -0.1 : 0);
	map->lxy += (keycode == 69 ? 1 : 0);
	map->lxy += (keycode == 78 ? -1 : 0);
	map->radx += (keycode == 13 ? (10 * M_PI / 180) : 0);
	map->radx += (keycode == 1 ? -(10 * M_PI / 180) : 0);
	map->radz += (keycode == 15 ? (10 * M_PI / 180) : 0);
	map->radz += (keycode == 17 ? -(10 * M_PI / 180) : 0);
	map->rady += (keycode == 0 ? -(10 * M_PI / 180) : 0);
	map->rady += (keycode == 2 ? (10 * M_PI / 180) : 0);
}

static void	ft_clear(t_map *map)
{
	t_map *new_map;

	new_map = (t_map *)map;
	mlx_clear_window(new_map->mlx_ptr, new_map->win_ptr);
	clear_img_str(map);
}

int			deal_key(int keycode, void *map)
{
	t_map *new_map;

	new_map = (t_map *)map;
	ft_putnbr(keycode);
	ft_putchar('\n');
	key_action(keycode, map);
	ft_clear(new_map);
	ft_new_matrix(new_map, new_map->p_matrix);
	draw_xlines(new_map, new_map->p_matrix);
	mlx_put_image_to_window(new_map->mlx_ptr, new_map->win_ptr
		, new_map->image, 0, 0);
	draw_info(map);
	return (0);
}
