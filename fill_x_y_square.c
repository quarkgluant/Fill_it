/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_x_y_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcadiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 18:35:32 by pcadiot           #+#    #+#             */
/*   Updated: 2016/09/20 18:35:42 by pcadiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int			*list_to_tab(t_list *list_grid, char obst, int size_line)
{
	int		*res;
	int		i;

	if (((res = malloc(sizeof(int) * size_line *
		count_columns(list_grid))) == NULL))
		exit(-1);
	i = 0;
	while (list_grid->next)
	{
		if (list_grid->data != '\n')
		{
			if (list_grid->data == obst)
				res[i] = 0;
			else
			{
				res[i] = 1;
				if (i > size_line)
					res[i] = ft_min(res[i - 1], res[i - size_line],
						res[i - (size_line + 1)]);
			}
			i++;
		}
		list_grid = list_grid->next;
	}
	return (res);
}

int			find_max(int *tab, t_list *list_grid)
{
	int		i;
	int		max;
	int		size;

	ft_fill_x_y(list_grid);
	size = ft_find_size_one_line(list_grid) * count_columns(list_grid);
	i = 0;
	max = 0;
	while (i < size)
	{
		max = (max > tab[i]) ? max : tab[i];
		i++;
	}
	return (max);
}

int			find_pos_max(int *tab, t_list *list_grid)
{
	int		i;
	int		max;

	i = 0;
	max = find_max(tab, list_grid);
	while (i < ft_find_size_one_line(list_grid) * count_columns(list_grid))
	{
		if (tab[i] == max)
			break ;
		i++;
	}
	return (i);
}

t_list		*make_grid(t_list *list_grid, int max, char fill, int pos)
{
	int		x;
	int		y;
	int		size_line;
	t_list	*list;

	list = list_grid;
	size_line = ft_find_size_one_line(list_grid);
	x = pos % size_line;
	y = pos / size_line;
	if (max >= 1)
	{
		while (list_grid->next)
		{
			if (list_grid->x > (x - max) && list_grid->x <= x
				&& list_grid->y > (y - max) && list_grid->y <= y)
				list_grid->data = fill;
			list_grid = list_grid->next;
		}
	}
	return (list);
}

t_list		*principal(t_list *list)
{
	char	obs;
	char	to_fill;
	int		size_line;
	int		max[2];
	int		*res;

	obs = ft_find_obs(list);
	to_fill = ft_find_fill(list);
	size_line = ft_find_size_one_line(list);
	res = list_to_tab(ft_strip_fisrt_line(list), obs, size_line);
	max[0] = find_max(res, list);
	max[1] = find_pos_max(res, list);
	return (make_grid(ft_strip_fisrt_line(list), max[0], to_fill, max[1]));
}
