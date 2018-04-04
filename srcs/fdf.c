/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 02:09:31 by mzabalza          #+#    #+#             */
/*   Updated: 2018/03/24 01:19:57 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static  int	fdf_init(t_map *map, char *doc)
{
	map->dx = 0;
	map->dy = 0;
	map->nb_col = 0;
	map->nb_row = 0;
	map->doc = doc;
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, WIDTH, HEIGHT, "prueba mlx");
	//si el open falla que devolvia??
	if (!(map->fd = open(map->doc, O_RDONLY)))
		return (0);
	return (1);
}

int 			main(int ac, char **av)
{
	void 	*mlx_ptr;
	void 	*win_ptr;
	t_map	map;
	int i;
	int j;

	if (ac != 2)
		return (ft_error("Usage : ./fdf <filename> [ case_size z_size ]", 1));
	if (!(fdf_init(&map, av[1])))
		return (ft_error("Error", 1));
	if (!(ft_parser(&map)))
		return (ft_error("Error", 1));
	draw_map(&map);
	//print_line(map);
	//print_2dmap(map);

	mlx_loop(map.mlx_ptr);
	return (0);
}
