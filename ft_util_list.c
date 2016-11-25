/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcadiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 19:08:56 by pcadiot           #+#    #+#             */
/*   Updated: 2016/09/21 10:59:31 by pcadiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

int			count_columns(t_list *list)
{
	int		column;
	t_list	*my_list;

	column = 0;
	my_list = ft_strip_fisrt_line(list);
	while (list->next != NULL)
	{
		if (my_list->data == '\n')
			break ;
		column++;
		my_list = my_list->next;
	}
	return (column);
}

t_list		*parse_file(char *path)
{
	t_list	*begin_list;
	int		pos;
	int		fd;
	char	car;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit(-1);
	read(fd, &car, 1);
	begin_list = ft_create_elem(car);
	while ((pos = read(fd, &car, 1)))
	{
		ft_list_push_back(begin_list, car);
	}
	return (begin_list);
}

int			size_list(t_list *list)
{
	int		size;

	size = 1;
	while (list->next != NULL)
	{
		size++;
		list = list->next;
	}
	return (size);
}
