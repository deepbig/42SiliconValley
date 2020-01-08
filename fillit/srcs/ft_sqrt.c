/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 16:44:25 by bpace             #+#    #+#             */
/*   Updated: 2019/08/21 14:34:51 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int num)
{
	int i;

	i = 1;
	while ((i * i) < num)
		i++;
	return (i);
}

char	**getmap(int mapsize)
{
	int		i;
	int		j;
	char	**map;

	map = (char **)malloc(sizeof(*map) * (mapsize + 1));
	i = -1;
	while (++i < mapsize)
	{
		j = -1;
		map[i] = ft_strnew(mapsize + 1);
		while (++j < mapsize + 1)
		{
			if (j % (mapsize + 1) == mapsize)
				map[i][j] = '\n';
			else
				map[i][j] = '.';
		}
		map[i][j] = '\0';
	}
	map[i] = 0;
	return (map);
}

int		getmapsize(t_coord *pieces)
{
	int		i;
	int		mapsize;

	i = 0;
	while (pieces)
	{
		i++;
		pieces = pieces->next;
	}
	mapsize = ft_sqrt(i * 4);
	return (mapsize);
}

void	freemap(char **map, int mapsize)
{
	int		i;

	i = -1;
	while (++i < mapsize)
	{
		ft_strdel(&map[i]);
		map[i] = 0;
	}
	ft_memdel((void **)&map);
}

int		checkbuff(int i, int j, t_coord *piece, int mapsize)
{
	int		co;
	int		ro;
	int		squ;

	squ = 0;
	while (++squ < 4)
	{
		co = j + piece[squ].col - piece[0].col;
		ro = i + piece[squ].row - piece[0].row;
		if (co < 0 || ro < 0 || co >= mapsize || ro >= mapsize)
			return (0);
	}
	return (1);
}
