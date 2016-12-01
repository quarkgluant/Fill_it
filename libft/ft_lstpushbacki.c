/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushbacki.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 19:54:27 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/22 20:59:23 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushbacki(t_listi **begin_list, int data)
{
	t_listi		*list;

	list = *begin_list;
	if (list)
	{
		while (list->next)
		{
			list = list->next;
		}
		list->next = ft_create_elemi(data);
	}
	else
		*begin_list = ft_create_elemi(data);
}
