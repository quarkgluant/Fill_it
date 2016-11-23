/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcadiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 09:44:39 by pcadiot           #+#    #+#             */
/*   Updated: 2016/09/21 21:00:30 by pcadiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int			ft_min(int x, int y, int z)
{
	int		result;

	if (x == y && y == z)
		result = x;
	if (x <= y && x <= z)
		result = x;
	if (y <= z && y <= x)
		result = y;
	if (z <= x && z <= y)
		result = z;
	return (result + 1);
}

int			ft_find_size_one_line(t_list *list)
{
	t_list	*my_list;
	int		size_line;

	my_list = ft_strip_fisrt_line(list);
	size_line = 0;
	while (my_list->next != NULL)
	{
		if (my_list->data == '\n')
			break ;
		size_line++;
		my_list = my_list->next;
	}
	return (size_line);
}

int			ft_fill_x_y(t_list *list)
{
	int		x;
	int		y;
	t_list	*my_list;

	my_list = ft_strip_fisrt_line(list);
	x = 0;
	y = 0;
	while (my_list->next != NULL)
	{
		my_list->x = x;
		my_list->y = y;
		x++;
		if (my_list->data == '\n')
		{
			x = 0;
			y++;
		}
		my_list = my_list->next;
	}
	return (0);
}
