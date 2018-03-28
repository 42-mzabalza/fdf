/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ndigits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:43:03 by mzabalza          #+#    #+#             */
/*   Updated: 2018/03/28 17:49:03 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
**Returns number of digts of number nb (nb = 0, 1 digit)
*/
int		ft_ndigits(int nb)
{
	int rtn;

	if (nb == 0)
		return (1);
	rtn = 0;
	while (nb != 0)
	{
		nb /= 10;
		rtn++;
	}
	return (rtn);
}
