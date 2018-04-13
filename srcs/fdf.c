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

// static int gere_mouse(int x,int y,int button,void*toto)
// {
//   printf("Mouse event - new win\n");
//   mlx_destroy_window(mlx,win1);
//   win1 = mlx_new_window(mlx,random()%500,random()%500,"new win");
//   mlx_mouse_hook(win1,gere_mouse,0);
// }

//METER ERROR EN LIBFT

static  void	image_init(t_map *map)
{
	int bpp;
	int endian;
	int l_size;

	map->image = mlx_new_image(map->mlx_ptr, WIDTH, HEIGHT);
	map->img_str = (int *)mlx_get_data_addr(map->image, &bpp, &l_size, &endian);
}

static  int		fdf_init(t_map *map, char *doc)
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
	map->line_size = WIDTH * 4;
	map->nb_col = 0;
	map->nb_row = 0;
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, WIDTH, HEIGHT, "prueba mlx");
	image_init(map);
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
	create_points(&map);

	mlx_key_hook(map.win_ptr, deal_key, &map);
	//mlx_mouse_hook(map.win_ptr,gere_mouse,0);
	mlx_loop(map.mlx_ptr);
	return (0);
}