/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manip_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcadiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 19:07:01 by pcadiot           #+#    #+#             */
/*   Updated: 2016/09/20 19:11:11 by pcadiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_create_elem(char data)
{
	t_list	*my_list;

	my_list = malloc(sizeof(t_list));
	if (my_list)
	{
		my_list->data = data;
		my_list->next = NULL;
	}
	return (my_list);
}

void		ft_list_push_back(t_list *begin_list, char data)
{
	t_list	*tmp;

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
