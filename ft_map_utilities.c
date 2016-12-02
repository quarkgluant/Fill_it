/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcadiot <pcadiot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:17:15 by pcadiot           #+#    #+#             */
/*   Updated: 2016/12/02 12:17:18 by pcadiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_mapissolved(t_map *map, t_list *lst, int x, int y)
{
	t_etris		*forme;

	forme = (t_etris *)lst->content;
	if (ft_copypossible(map, forme, x, y))
	{
		ft_copy(map, forme, x, y);
		if (lst->next)
		{
			if (ft_mapsolved(map, lst->next))
				return (1);
			else
				ft_erase(map, forme, x, y);
		}
		else
			return (1);
	}
	return (0);
}

t_map		*ft_newmap(int size)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = size;
	map->array = (char **)ft_memalloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		map->array[i] = (char *)ft_memalloc(sizeof(char) * size);
		j = 0;
		while (j < size)
		{
			map->array[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

t_map		*ft_solvemap(t_list *lst)
{
	int		size;
	t_map	*map;

	size = ft_findsizemap(lst);
	map = ft_newmap(size);
	while (!ft_mapsolved(map, lst))
	{
		size++;
		ft_freemap(map);
		map = ft_newmap(size);
	}
	return (map);
}

void		ft_printmap(t_map *map)
{
	int i;
	int j;
	int	size;

	size = map->size;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(map->array[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
