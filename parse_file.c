/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcadiot <pcadiot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:26:21 by pcadiot           #+#    #+#             */
/*   Updated: 2016/11/23 15:26:25 by pcadiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

t_list			*ft_create_elem(char data)
{
	t_list		*my_list;

	my_list = malloc(sizeof(t_list));
	if (my_list)
	{
		my_list->data = data;
		my_list->next = NULL;
	}
	return (my_list);
}

t_tet_list		*create_tet(char *str)
{
	t_tet_list	*my_list;
	int			i;

	i = 0;
	my_list = malloc(sizeof(t_tet_list));
	if (my_list)
	{
		while (i < 16)
		{
			my_list->tetra[i] = str[i];
			i++;		
		}
		my_list->next = NULL;
	}
	return (my_list);
}

void			ft_list_push_back(t_list *begin_list, char data)
{
	t_list		*tmp;

	if (begin_list == NULL)
	{
		begin_list = ft_create_elem(data);
		if (begin_list == NULL)
			exit(-1);
	}
	else
	{
		tmp = begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_elem(data);
	}
}

void			tet_list_push_back(t_tet_list *begin_list, char *str)
{
	t_tet_list	*tmp;

	if (begin_list == NULL)
	{
		begin_list = create_tet(str);
		if (begin_list == NULL)
			exit(-1);
	}
	else
	{
		tmp = begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_tet(str);
	}
}

t_list			*parse_file(char *path)
{
	t_list		*begin_list;
	int			pos;
	int			fd;
	char		car;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit(-1);
	read(fd, &car, 1);
	begin_list = ft_create_elem(car);
	while ((pos = read(fd, &car, 1)))
		ft_list_push_back(begin_list, car);
	return (begin_list);
}
