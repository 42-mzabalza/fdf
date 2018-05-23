/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 15:27:20 by mzabalza          #+#    #+#             */
/*   Updated: 2018/04/16 20:34:43 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>

# define WIDTH 2000
# define HEIGHT 1300
# define WHITE 0xffffff
# define BLACK 0x000000
# define RED 0xff0000
# define GREEN 0x00ff00
# define BLUE 0x0000ff
# define BROWN 0x614126

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
	float			color;

}					t_point;

typedef struct		s_map
{
	int				persp;
	float			radx;
	float			rady;
	float			radz;
	char			*doc;
	void			*mlx_ptr;
	void			*win_ptr;
	int				fd;
	void			*image;
	int				*img_str;
	int				tx;
	int				ty;
	int				lxy;
	float			height;
	int				nb_col;
	int				nb_row;
	int				**matrix;
	t_point			**p_matrix;
	int				z_range[2];
	int				color;

}					t_map;

typedef struct		s_breshm_line
{
	float			color;
	float			gradient;
	float			dxy[2];
	float			sxy[2];
	int				p0[2];
	int				p1[2];

}					t_breshm_line;

/*
**----------GENERAL FUNCTIONS--------------------------------------------------
*/
int					main(int ac, char **av);
void				show_map(t_map *map);
void				show_p_matrix(t_map *map, t_point **p_matrix);
int					create_points(t_map *map);
int					ft_error(char *str, int rtn_value);
int					ft_parser(t_map *map);
int					get_next_line(const int fd, char **line);
void				ft_new_matrix(t_map *map, t_point **p_matrix);
void				free_matrix(t_map *map, int m, int p);
void				exit_fdf(int keycode, t_map *map);
/*
**----------GEOMETRIC TRANSFORMATIONS------------------------------------------
*/
void				ft_rotate(t_map *map, t_point **p_matrix, int i, int j);
void				rotate_y(float *x, float *z, float rad);
void				rotate_x(float *y, float *z, float rad);
void				rotate_z(float *x, float *y, float rad);
void				add_perspective(t_map *map, t_point **p_matrix);
/*
**----------DRAWING -----------------------------------------------------------
*/
void				draw_points(t_map *map, t_point **p_matrix);
void				draw_xlines(t_map *map, t_point **p_matrix);
void				draw_info(t_map *map);
/*
**----------EVENT MANAGEMENT---------------------------------------------------
*/
void				fill_img_str(int *img_str, int x, int y, int color);
void				clear_img_str(t_map *map);
/*
**----------EVENT MANAGEMENT---------------------------------------------------
*/
int					deal_key(int key, void *param);
/*
**----------EVENT MANAGEMENT---------------------------------------------------
*/
float				select_color(t_map *map, int z);
float				color_gradient(t_point p1, t_point p2, float dx, float dy);

#endif
