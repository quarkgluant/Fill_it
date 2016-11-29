/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 17:39:35 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/29 21:09:05 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
			if (str[i] != '\n')
				return (0);
		i++;
	}
		if ((count == 21) && str[20] != '\n')
		return (0);
	return (1);
}

int			ft_checkneighbor(char	*str)
{
	int		i;
	int		neighbor;

	neighbor = 0;
	i =0;
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

t_etris		*create_maillon(char *str, char value)
{
	int			i;
	int			tab[4];
	char		**forme;
	t_etris		*mail;

	ft_max_size(str, tab);
	forme = (char **)ft_memalloc(sizeof(char *) * (tab[3] - tab[1] + 1));
	i = 0;
	while ( i < (tab[3] - tab[1] + 1))
	{
		forme[i] = ft_strnew((tab[2] - tab[0] + 1));
		ft_strncpy(forme[i], str + (tab[0] + (i + tab[1]) * 5), tab[2] - tab[0] + 1);
		i++;
	}
	mail = tetris_new(forme,tab[2] - tab[0] + 1, tab[3] - tab[1] + 1, value);
	return (mail);	
}

int			ft_addtetrimino(t_list **lst, char *tab, char value)
{
	int		i;
	char	**tableau;
	t_etris	*ret;

	ret = create_maillon(tab, value);
	ft_lstaddlast(lst, ft_lstnew(ret, sizeof(t_etris)));
	return (1);
}

t_list		*ft_readfile(int fc)
{
	int		ret;
	char	*tab;
	t_list	**lst;
	char	value;

	lst = (t_list **)malloc(sizeof(t_list *));
	*lst = NULL;
	value = 'A';
	tab = ft_strnew(21);
	while ((ret = read(fc, tab, 21)) > 0)
	{
		if (!(ft_checkneighbor(tab) && ft_checkstring(ret, tab)
				&& ft_addtetrimino(lst,tab,value++)))
		{
			ft_memdel((void **)&tab);
			return (*lst);
		}
	}
	ft_memdel((void **)&tab);
	return (*lst);
}

void	ft_printmap(t_map *map)
{
	int i;
	int j;
	int	size;

	size = map->size;
	i = 0;
	while (i < size)
	{
		ft_putendl(map->array[i]);
		i++;
	}
}

t_map	*ft_newmap(int size)
{
	t_map 	*map;
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

int		ft_copy(t_map *map, t_etris *forme, int x, int y)
{
	int		i;
	int		j;

	j = 0;
	while (j < forme->height)
	{
		i = 0;
		while (i < forme->width)
		{
			if (forme->pos[j][i] == '#' && map->array[y + j][x + i] == '.')
				map->array[y + j][x + i] = forme->value;
			i++;
		}
		j++;
	}
	return (1);
}

int		ft_copypossible (t_map *map, t_etris *forme, int x, int y)
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

int		ft_mapsolved(t_map *map, t_list *lst)
{
	t_etris		*forme;
	int			x;
	int			y;
	int			size;

	size = map->size;
	y = 0;
	forme = (t_etris *)lst->content;
	while ( y < (size - forme->height + 1))
	{
		x = 0;
		while ( x < (size - forme->width + 1))
		{
			if (ft_copypossible(map, forme, x, y))
			{
				ft_copy(map, forme, x, y);
				if (lst->next)
				{
					if (ft_mapsolved(map, lst->next))
						return (1);
				}
				else
					return (1);
			}
			x++;
		}
		y++;
	}
	ft_printmap(map);
	return(0);
}

t_map	*ft_solvemap(t_list *lst)
{
	int		size;
	t_map	*map;

	size = ft_findsizemap(lst);
	ft_putnbreol(size);
	map = ft_newmap(size);
	while (!ft_mapsolved(map, lst))
	{
		size++;
		free(map);
		map = ft_newmap(size);
	}
	return (map);
}
int		main(int argc, char **argv)
{
	int		fc;
	t_list	*lst;
	t_map	*map;
	int  	j;
	t_etris *forme;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	fc = open(argv[1], O_RDONLY);
	if (fc == -1)
	{
		ft_putstr("File cannot be read\n");
		return (1);
	}
	if ((lst = ft_readfile(fc)) == NULL)
		close (fc);
	else
	{
		map = ft_solvemap(lst);
		ft_printmap(map);
		ft_putstr("reussi\n");
	}
}
