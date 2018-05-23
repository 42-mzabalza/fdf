/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 02:09:31 by mzabalza          #+#    #+#             */
/*   Updated: 2018/04/16 19:15:43 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		image_init(t_map *map)
{
	int bpp;
	int endian;
	int l_size;

	map->image = mlx_new_image(map->mlx_ptr, WIDTH, HEIGHT);
	map->img_str = (int *)mlx_get_data_addr(map->image, &bpp, &l_size, &endian);
}

static int		fdf_init(t_map *map, char *doc)
{
	map->doc = doc;
	map->fd = open(map->doc, O_RDONLY);
	if (map->fd == -1)
		return (0);
	map->height = 1;
	map->radx = 0.0;
	map->rady = 0.0;
	map->radz = 0.0;
	map->tx = WIDTH * 0.3;
	map->ty = HEIGHT * 0.2;
	map->nb_col = 0;
	map->nb_row = 0;
	map->color = 0;
	return (1);
}

int				main(int ac, char **av)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;
	int		i;
	int		j;

	if (ac != 2)
		return (ft_error("Usage : ./fdf <filename> [ case_size z_size ]", 1));
	if (!(fdf_init(&map, av[1])))
		return (ft_error("Error", 1));
	if (!(ft_parser(&map)))
		return (ft_error("Error", 1));
	map.mlx_ptr = mlx_init();
	map.win_ptr = mlx_new_window(map.mlx_ptr, WIDTH, HEIGHT, "prueba mlx");
	image_init(&map);
	create_points(&map);
	mlx_key_hook(map.win_ptr, deal_key, &map);
	mlx_loop(map.mlx_ptr);
	return (0);
}
