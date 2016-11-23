/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_find_caract.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcadiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 09:47:02 by pcadiot           #+#    #+#             */
/*   Updated: 2016/09/21 09:47:06 by pcadiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

char		ft_find_free(t_list *list)
{
	while (list->data >= '0' && list->data <= '9')
	{
		list = list->next;
	}
	return (list->data);
}

char		ft_find_obs(t_list *list)
{
	while (list->data >= '0' && list->data <= '9')
	{
		list = list->next;
	}
	list = list->next;
	return (list->data);
}

char		ft_find_fill(t_list *list)
{
	while (list->data >= '0' && list->data <= '9')
	{
		list = list->next;
	}
	list = list->next;
	list = list->next;
	return (list->data);
}
