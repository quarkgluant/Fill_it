/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcadiot <pcadiot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:21:52 by pcadiot           #+#    #+#             */
/*   Updated: 2016/12/02 12:21:55 by pcadiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_checkneighbor(char *str)
{
	int		i;
	int		neighbor;

	neighbor = 0;
	i = 0;
	while (i <= 20)
	{
		if (str[i] == '#')
		{
			if (((i - 1) >= 0) && (str[i - 1] == '#'))
				neighbor++;
			if (((i + 1) <= 19) && (str[i + 1] == '#'))
				neighbor++;
			if (((i - 5) >= 0) && (str[i - 5] == '#'))
				neighbor++;
			if (((i + 5) <= 19) && (str[i + 5] == '#'))
				neighbor++;
		}
		i++;
	}
	return (((neighbor == 6) || (neighbor == 8)));
}

int			ft_checkstring(int count, char *str)
{
	int		i;
	int		block;

	i = 0;
	block = 0;
	while (i < 20)
	{
		if ((i % 5) < 4)
		{
			if (str[i] != '#' && str[i] != '.')
				return (0);
			if (str[i] == '#' && (++block > 4))
				return (0);
		}
		else
		{
			if (str[i] != '\n')
				return (0);
		}
		i++;
	}
	if ((count == 21) && str[20] != '\n')
		return (0);
	return (1);
}

int			ft_copypossible(t_map *map, t_etris *forme, int x, int y)
{
	int		i;
	int		j;

	j = 0;
	while (j < forme->height)
	{
		i = 0;
		while (i < forme->width)
		{
			if (forme->pos[j][i] == '#' && map->array[y + j][x + i] != '.')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int			ft_nbargnotvalide(int argc)
{
	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	return (0);
}

int			ft_mapsolved(t_map *map, t_list *lst)
{
	t_etris		*forme;
	int			x;
	int			y;
	int			size;

	size = map->size;
	y = 0;
	forme = (t_etris *)lst->content;
	while (y < (size - forme->height + 1))
	{
		x = 0;
		while (x < (size - forme->width + 1))
		{
			if (ft_mapissolved(map, lst, x, y))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
