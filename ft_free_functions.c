/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcadiot <pcadiot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:24:49 by pcadiot           #+#    #+#             */
/*   Updated: 2016/12/02 12:24:52 by pcadiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_freetetris(t_etris *tetris)
{
	int		i;
	int		size;

	i = 0;
	size = tetris->height;
	while (i < size)
		ft_memdel((void **)&(tetris->pos[i++]));
	ft_memdel((void **)&(tetris->pos));
	ft_memdel((void **)&tetris);
	free(&(tetris->pos));
}

void		ft_freelst(t_list **lst)
{
	t_list	*next;
	t_etris	*tetris;

	while (*lst)
	{
		tetris = (t_etris *)(*lst)->content;
		next = (*lst)->next;
		ft_freetetris(tetris);
		ft_memdel((void **)lst);
		*lst = next;
	}
	free(lst);
}

t_list		**ft_erasemem(char *tab, t_list **lst)
{
	ft_memdel((void **)&tab);
	ft_freelst(lst);
	return (NULL);
}

void		ft_freemap(t_map *map)
{
	int		i;
	int		size;

	size = map->size;
	i = 0;
	while (i < size)
	{
		ft_memdel((void **)&(map->array[i]));
		i++;
	}
	ft_memdel((void **)&(map->array));
	ft_memdel((void **)&map);
}

int			ft_erase(t_map *map, t_etris *forme, int x, int y)
{
	int		i;
	int		j;

	j = 0;
	while (j < forme->height)
	{
		i = 0;
		while (i < forme->width)
		{
			if (forme->pos[j][i] == '#'
					&& map->array[y + j][x + i] == forme->value)
				map->array[y + j][x + i] = '.';
			i++;
		}
		j++;
	}
	return (1);
}
