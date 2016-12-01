/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 21:27:31 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/27 20:35:55 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_restlstaddns(t_lists *lst, char *data, int n)
{
	int		cpt;
	t_lists	*prev;

	cpt = 0;
	while ((lst) && (++cpt < n))
	{
		prev = lst;
		lst = lst->next;
	}
	if (cpt == n)
	{
		prev->next = ft_create_elems(data);
		prev->next->next = lst;
	}
}

t_lists			*ft_lstaddns(t_lists *lst, char *data, int n)
{
	t_lists	*first;

	first = lst;
	if ((lst) && n > 0)
	{
		if (n == 1)
		{
			first = ft_create_elems(data);
			first->next = lst;
			return (first);
		}
		ft_restlstaddns(lst, data, n);
	}
	return (first);
}
