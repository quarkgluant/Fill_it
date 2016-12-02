/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 01:58:34 by jblancha          #+#    #+#             */
/*   Updated: 2016/12/01 22:16:45 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_etris		*tetris_new(char **pos, int width, int height, char value)
{
	t_etris		*tetris;

	tetris = ft_memalloc(sizeof(t_etris));
	tetris->pos = pos;
	tetris->width = width;
	tetris->height = height;
	tetris->value = value;
	return (tetris);
}

void		ft_max_size(char *str, int *tab)
{
	int		i;

	i = 0;
	tab[0] = 3;
	tab[1] = 3;
	tab[2] = 0;
	tab[3] = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i / 5) < tab[1])
				tab[1] = (i / 5);
			if ((i / 5) > tab[3])
				tab[3] = (i / 5);
			if ((i % 5) < tab[0])
				tab[0] = (i % 5);
			if ((i % 5) > tab[2])
				tab[2] = (i % 5);
		}
		i++;
	}
}

int			ft_countlst(int n)
{
	int size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

int			ft_maxlst(t_list *lst)
{
	int		max;
	t_list	*lst1;

	lst1 = lst;
	max = 0;
	while (lst1)
	{
		if (max < ((t_etris *)lst1->content)->width)
			max = ((t_etris *)lst1->content)->width;
		if (max < ((t_etris *)lst1->content)->height)
			max = ((t_etris *)lst1->content)->height;
		lst1 = lst1->next;
	}
	return (max);
}

int			ft_findsizemap(t_list *lst)
{
	int		sizelst;
	int		countlst;

	sizelst = ft_maxlst(lst);
	countlst = ft_countlst(ft_lstsize(lst) * 4);
	if (sizelst > countlst)
		return (sizelst);
	else
		return (countlst);
}
