/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 19:27:58 by mzabalza          #+#    #+#             */
/*   Updated: 2018/04/09 19:28:02 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_clear(void *map)
{
	t_map *new_map;

	new_map = (t_map *)map;
	mlx_clear_window(new_map->mlx_ptr, new_map->win_ptr);
	return ;
}

int			deal_key(int keycode, void *map)
{
	t_map *new_map;

	new_map = (t_map *)map;
	ft_putnbr(keycode);
	// (void)mlx;
	if (keycode == 53) //53 = ESC
	{
		// mlx_destroy_window
		exit(1);
	}
	if (keycode == 124) // RIGHT ARROW
		traslation(new_map, 10, 0);
	if (keycode == 123) // LEFT ARROW
		traslation(new_map, -10, 0);
	if (keycode == 126) // UP ARROW
		traslation(new_map, 0, -10);
	if (keycode == 125) // DOWN ARROW
		traslation(new_map, 0, 10);
	if (keycode == 46) // m key
		add_height(new_map, new_map->p_matrix, 5);
	if (keycode == 45) // n key
		add_height(new_map, new_map->p_matrix, -5);
	// if (keycode == 15) // r key - rotate
	// 	rotate(new_map, new_map->p_matrix, 30 * M_PI / 180);
	if (keycode == 69) // + key
		scaling(new_map, new_map->p_matrix, 2);
	if (keycode == w) // w key
		rotate_y(new_map, new_map->p_matrix, 30 * M_PI / 180);
	ft_clear(new_map);
	draw_xlines(map, new_map->p_matrix);
	draw_ylines(map, new_map->p_matrix);
	ft_putchar('\n');
	return (0);
}

 // mouse_hook(int button,int x,int y,void *param);
//  x
// ,
// .I y
// ) are the coordinates of the mouse click in the window, and
// .I button
// tells you which mouse button was pressed.

