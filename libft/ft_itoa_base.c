/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 19:15:11 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/03 15:50:37 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_digits(unsigned int nb, unsigned int base)
{
	int digits;

	digits = 1;
	while (nb >= base)
	{
		nb /= base;
		digits++;
	}
	return (digits);
}

char		*ft_itoa_base(unsigned int nb, int base)
{
	int		ndigits;
	char	*dst;
	int		remain;

	ndigits = ft_digits(nb, base);
	if (!(dst = (char *)malloc(sizeof(char) * (ndigits + 1))))
		return (NULL);
	while (ndigits-- > 0)
	{
		remain = nb % base;
		if (remain > 9)
			remain = remain - 10 + 'a';
		else
			remain = remain + '0';
		dst[ndigits] = remain;
		nb /= base;
	}
	return (dst);
}
