/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsizes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:10:52 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/23 17:11:15 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsizes(t_lists *begin_list)
{
	t_lists	*list;
	int		cpt;

	cpt = 0;
	list = begin_list;
	if (list)
	{
		cpt = 1;
		while (list->next)
		{
			list = list->next;
			cpt++;
		}
	}
	return (cpt);
}
