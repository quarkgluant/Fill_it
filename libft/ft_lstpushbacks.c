/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushbacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:08:37 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/23 17:09:24 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushbacks(t_lists **begin_list, char *data)
{
	t_lists		*list;

	list = *begin_list;
	if (list)
	{
		while (list->next)
		{
			list = list->next;
		}
		list->next = ft_create_elems(data);
	}
	else
		*begin_list = ft_create_elems(data);
}
