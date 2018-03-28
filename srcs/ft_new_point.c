/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:30:35 by mzabalza          #+#    #+#             */
/*   Updated: 2018/03/26 14:36:01 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point		*ft_new_point()
{
	t_point *newpoint;
	
	if (!(newpoint = (t_point *)malloc(sizeof(t_point))))
			exit(1);

	newpoint->x = 0;
	newpoint->y = 0;
	newpoint->z = 0;
	newpoint->next = NULL;
	newpoint->prev = NULL;
	return (newpoint);
}
