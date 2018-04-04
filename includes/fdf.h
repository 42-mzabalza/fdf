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
# include "mlx.h"
# include <fcntl.h>
# include <math.h>

# define WIDTH 1000
# define HEIGHT 1000

/*
**map->size		size of output window
**map->x			number of columns
**map->y			number of rows
**map->matrix	map stored in a char **variable
*/

typedef struct 		s_point
{
	int				x;
	int				y;

}					t_point;

typedef struct 		s_map
{
	int				slopex;
	int				slopey;
	char			*doc;
	void 			*mlx_ptr;
	void 			*win_ptr;
	int				fd;
	int				scal;
	int				dx;
	int				sx;
	int				dy;
	int				sy;
	int				p1[2];
	int				p2[2];
	int				nb_col;
	int				nb_row;
	int				**matrix;
	t_point			**p_matrix;

}					t_map;


int 				main(int ac, char **av);
void				show_map(t_map *map);
void				show_p_matrix(t_map *map, t_point **p_matrix);
void 				print_2dmap(t_map *map);
int					draw_map(t_map *map);
int					ft_error(char *str, int rtn_value);
int					ft_parser(t_map *map);
int					get_next_line(const int fd, char **line);
#endif
