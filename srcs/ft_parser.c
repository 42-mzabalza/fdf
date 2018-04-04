/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:46:08 by mzabalza          #+#    #+#             */
/*   Updated: 2018/04/04 13:46:10 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	alloc_map(t_map *map)
{
	int 	i;
	char 	*line;
	char 	**tab;

	i = 0;
	while (get_next_line(map->fd, &line) > 0)
	{
		tab = ft_strsplit(line, ' ');
		while (tab[i])
		{
			i++;
			free(tab[i]);
		}
		if (map->nb_row == 0)
			map->nb_col = i;
		else
			if (map->nb_col != i)
				return (0);
		(map->nb_row)++;
		free(line);
	}
	free(tab);
	close(map->fd);
	return (1);
}

static int	store_map(t_map *map)
{
	int 	i;
	int 	j;
	char 	*line;
	char 	**tab;
	
	j = 0;
	while (get_next_line(map->fd, &line) > 0)
	{
		map->matrix[j] = (int *)malloc(sizeof(int) * (map->nb_col));
		tab = ft_strsplit(line, ' ');
		i = 0;
		while (tab[i])
		{
			if (!(ft_isnum(tab[i])))
				return (0);
			map->matrix[j][i] = ft_atoi(tab[i]);
			free(tab[i]);
			i++;
		}
		free(tab);
		free(line);
		j++;
	}
	close(map->fd);
	return (1);
}

int			ft_parser(t_map *map)
{	
	if (!alloc_map(map))
		return (0);
	map->matrix = (int **)malloc(sizeof(int *) * (map->nb_row));
	if (!(map->fd = open(map->doc, O_RDONLY)))
		return (0);
	if (!store_map(map))
		return (0);
	return (1);
}
