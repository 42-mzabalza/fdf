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
		new_map->tx += 30;
	if (keycode == 123) // LEFT ARROW
		new_map->tx -= 30;
	if (keycode == 126) // UP ARROW
		new_map->ty -= 30;
	if (keycode == 125) // DOWN ARROW
		new_map->ty += 30;
	if (keycode == 46) // m key
		new_map->height += 0.5;
	if (keycode == 45) // n key
		new_map->height -= 0.5;
	// if (keycode == 15) // r key - rotate
	// 	rotate(new_map, new_map->p_matrix, 30 * M_PI / 180);
	if (keycode == 69) // + key ZOOM IN
		new_map->lxy += 10;
	if (keycode == 78) // - key ZOOM OUT
		new_map->lxy -= 10;
	if (keycode == 13) // w key
		new_map->radx += (10 * M_PI / 180); // intentar hacer el cambio mas tarde
	if (keycode == 1) // s key
		new_map->radx -= (10 * M_PI / 180); // intentar hacer el cambio mas tarde
		//rotate_x(new_map, new_map->p_matrix, 30 * M_PI / 180);
	if (keycode == 0) // a key
		new_map->rady -= (10 * M_PI / 180);
	if (keycode == 2) // d key
		new_map->rady += (10 * M_PI / 180); // intentar hacer el cambio mas tarde
	ft_clear(new_map);
	ft_new_matrix(new_map, new_map->p_matrix);
	draw_xlines(new_map, new_map->p_matrix);
	draw_ylines(new_map, new_map->p_matrix);
	//show_p_matrix(map, new_map->p_matrix);
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

