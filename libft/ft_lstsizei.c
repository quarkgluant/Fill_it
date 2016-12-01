/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsizei.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 21:19:37 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/22 21:19:45 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsizei(t_listi *begin_list)
{
	t_listi	*list;
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
