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

//OJO si el input HEXADECIMAL
static int		*ft_parse_line(t_map *map, char *line)
{
	int i;
	int *dst;
	int a;

	i = 0;
	if (!(dst = (int *)malloc(sizeof(int) * (map->x))))
		exit(1);
	while (*line)
	{
		if (*line != ' ')
		{
			dst[i] = ft_atoi(line);
	 		line += ft_ndigits(ft_atoi(line));
	 		i++;
		}
		else
			line++;
	}
	return (dst);
	
}

static int		**ft_parse_map(t_map *map, char *doc)
{
	int 	fd;
	int 	j;
	int		**dst;
	char 	*line;

	j = 0;
	if (!(dst = (int **)malloc(sizeof(int *) * (map->y))))
		exit(1);
	if (!(fd = open(doc, O_RDONLY)))
		exit(1);
	while (get_next_line(fd, &line) > 0)
	{
		dst[j] = ft_parse_line(map, line);
		j++;
	}
	return (dst);
}

static t_map 	*get_colrow(char *doc)
{
	int 	i;
	int 	fd;
	char 	*line;
	t_map 	*map;

	if (!(fd = open(doc, O_RDONLY)))
		exit(1);
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		exit(1);
	map->x = 0;
	map->y= 0;
	while (get_next_line(fd, &line) > 0)
	{
		i  = 0;
		while (line[i])
		{
			if (ft_isdigit(line[i]) && !(map->y))
				(map->x)++;
			i++;
		}
		(map->y)++;
	}
	map->matrix = ft_parse_map(map, doc);
	close(fd);
	return (map);
}

// static void 	print_line(void *mlx_ptr, void *win_ptr)
// {
// 	int i;
// 	i = 0;
// 	while (i < 1000)
// 	{
// 		mlx_pixel_put(mlx_ptr, win_ptr, i, 500, 0xFFFFFF);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < 1000)
// 	{
// 		mlx_pixel_put(mlx_ptr, win_ptr, 500, i, 0xFFFFFF);
// 		i++;
// 	}
// }

int 				main(int ac, char **av)
{
	// void *mlx_ptr;
	// void *win_ptr;
	int i;
	int j;
	t_map	*map;

	// mlx_ptr = mlx_init();
	// win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "prueba mlx");
	// if(!(map = read_map(ac, av)))
	// 	return (0);
	map = get_colrow(av[1]);
	ft_putnbr(map->x);
	ft_putnbr(map->y);

	//print_line(mlx_ptr, win_ptr);
	//mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	//mlx_loop(mlx_ptr);
	return (1);
}
