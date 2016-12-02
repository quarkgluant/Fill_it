/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 17:39:35 by jblancha          #+#    #+#             */
/*   Updated: 2016/12/01 22:11:52 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_etris		*create_maillon(char *str, char value)
{
	int			i;
	int			tab[4];
	char		**forme;
	t_etris		*mail;

	ft_max_size(str, tab);
	forme = (char **)ft_memalloc(sizeof(char *) * (tab[3] - tab[1] + 1));
	i = 0;
	while (i < (tab[3] - tab[1] + 1))
	{
		forme[i] = ft_strnew((tab[2] - tab[0] + 1));
		ft_strncpy(forme[i], str + (tab[0] + (i + tab[1]) * 5),
				tab[2] - tab[0] + 1);
		i++;
	}
	mail = tetris_new(forme, tab[2] - tab[0] + 1, tab[3] - tab[1] + 1, value);
	return (mail);
}

int			ft_addtetrimino(t_list **lst, char *tab, char value)
{
	t_etris	*ret;

	ret = create_maillon(tab, value);
	ft_lstaddlast(lst, ft_lstnew(ret, sizeof(t_etris)));
	ft_memdel((void **)&ret);
	return (1);
}

t_list		**ft_readfile(int fc)
{
	int		ret;
	char	*tab;
	t_list	**lst;
	char	value;
	int		prev;

	lst = (t_list **)malloc(sizeof(t_list *));
	*lst = NULL;
	value = 'A';
	prev = 0;
	tab = ft_strnew(21);
	while ((ret = read(fc, tab, 21)) > 0)
	{
		if (!(ft_checkneighbor(tab) && ft_checkstring(ret, tab)
				&& ft_addtetrimino(lst, tab, value++) && (ret >= 20)))
			return (ft_erasemem(tab, lst));
		prev = ret;
	}
	ft_memdel((void **)&tab);
	if (prev != 20)
	{
		ft_freelst(lst);
		return (NULL);
	}
	return (lst);
}

int			ft_copy(t_map *map, t_etris *forme, int x, int y)
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

int			main(int argc, char **argv)
{
	int		fc;
	t_list	**lst;
	t_map	*map;

	if (ft_nbargnotvalide(argc))
		return (1);
	if ((fc = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putstr("File cannot be read\n");
		return (1);
	}
	if ((lst = ft_readfile(fc)) == NULL)
	{
		ft_putstr("error\n");
		close(fc);
	}
	else
	{
		map = ft_solvemap(*lst);
		ft_printmap(map);
		ft_freemap(map);
		ft_freelst(lst);
		close(fc);
	}
	return (0);
}
