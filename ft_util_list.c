/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcadiot <pcadiot@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 11:48:56 by pcadiot           #+#    #+#             */
/*   Updated: 2016/11/27 13:59:31 by pcadiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

int			count_columns(t_list *list)
{
	int		column;

	column = 0;
	while (list->next != NULL)
	{
		if (list->data == '\n')
			break ;
		column++;
		list = list->next;
	}
	return (column);
}

int			size_list(t_list *list)
{
	int		size;

	size = 0;
	while (list)
	{
		size++;
		list = list->next;
	}
	return (size);
}
