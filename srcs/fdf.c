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
static void		matrix_init(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < (map->nb_row))
	{
		j = 0;
		while (j < (map->nb_col))
		{
			map->p_matrix[i][j].z = 0.0;
			map->p_matrix[i][j].x = 0.0;
			map->p_matrix[i][j].y = 0.0;
			j++;
		}
		i++;
	}
}

static  int		fdf_init(t_map *map, char *doc)
{
	map->doc = doc;
	//matrix_init(map);
	map->fd = open(map->doc, O_RDONLY);
	ft_putnbr(map->fd);
	if (map->fd == -1)
		return (0);
	ft_putchar('z');
	map->height = 1;
	map->radx = 0.0;
	map->rady = 0.0;
	map->radz = 0.0;
	map->tx = 0;
	map->ty = 0;
	map->nb_col = 0;
	map->nb_row = 0;
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, WIDTH, HEIGHT, "prueba mlx");
	//si el open falla que devolvia??
	
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
	//print_line(map);
	//print_2dmap(map);
	
	mlx_key_hook(map.win_ptr, deal_key, &map);
	//mlx_mouse_hook(map.win_ptr,gere_mouse,0);
	//mlx_clear_window(map.mlx_ptr, map.win_ptr);
	mlx_loop(map.mlx_ptr);
	
	return (0);
}
