/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 15:27:20 by mzabalza          #+#    #+#             */
/*   Updated: 2018/03/20 15:40:20 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
#include "mlx.h"
#include <fcntl.h>

/*
**map->size		size of output window
**map->x			number of columns
**map->y			number of rows
**map->matrix	map stored in a char **variable
*/

typedef struct 		s_map
{
	void 			*mlx_ptr;
	void 			*win_ptr;
	int				size;
	int				scal;
	int				x;
	int				y;
	int				**matrix;
}								t_map;

typedef struct	s_point
{
	int				x;
	int 			y;
}								t_point;

int 				main(int ac, char **av);
void	     	show_usage(void);
void 				print_2dmap(t_map *map);
void				print_line(t_map *map);

#endif
